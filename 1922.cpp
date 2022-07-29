#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent[1001];
struct Edge
{
    int from;
    int to;
    int cost;

    Edge(int a, int b, int c) : from(a), to(b), cost(c){}
};

struct compare
{
    bool operator()(const Edge& a, const Edge& b)
    {
        return a.cost > b.cost;
    }
};

int getParent(int index)
{
    if(parent[index] == index) return index;
    return parent[index] = getParent(parent[index]);
}

bool findParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);

    if(a == b) return true;
    return false;
}

void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);

    if(a > b) parent[a] = b;
    else parent[b] = a; 
}

int kruskal(int vertixNum, int edgeNum)
{
    priority_queue<Edge, vector<Edge>, compare> pq;
    int result = 0;

    for(int i = 0; i < edgeNum; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        pq.push(Edge(from, to, cost));
    }

    while(!pq.empty())
    {
        int from = pq.top().from;
        int to = pq.top().to;
        int cost = pq.top().cost;
        pq.pop();

        if(!findParent(from, to))
        {
            result += cost;
            unionParent(from, to);
        }
    }

    return result;
}

int main()
{
    int vertixNum, edgeNum;
    cin >> vertixNum >> edgeNum;

    for(int i = 1; i <= vertixNum; i++)
    {
        parent[i] = i;
    }

    cout << kruskal(vertixNum, edgeNum);
}