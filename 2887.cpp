//(플5) 2887 행성 터널
// 3차원 상의 좌표의 점이 주어지면 각 행성을 모두 연결하는 최소의 터널의 비용을 구하라
// 최소 스패닝 트리 - 크루스칼 알고리즘

#include <iostream>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

struct point
{
    long long x;
    long long y;
    long long z;
    int num;
};

struct edge
{
    int from;
    int to;
    long long cost;
};

struct compareEdge
{
    bool operator()(edge& a, edge& b)
    {
        return a.cost > b.cost;
    }
};

vector<point> planet;
int parent[100000];
int compareType = 0;

bool comparePoint(point& a, point& b)
{
    if(compareType == 0) return a.x > b.x;
    else if(compareType == 1) return a.y > b.y;  
    else return a.z > b.z;
}

int findParent(int x)
{
    if(x == parent[x]) return x;
    else return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y)
{
    x = findParent(x);
    y = findParent(y);
    if(x < y) parent[y] = x;
    else if(x > y) parent[x] = y;
}

int main()
{
    int n; cin >> n;
    long long result = 0;
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
        point temp; cin >> temp.x >> temp.y >> temp.z;
        temp.num = i;
        planet.push_back(temp);
    }

    priority_queue<edge, vector<edge>, compareEdge> pq;
    for(int i = 0; i < 3; i++, compareType++)
    {
        sort(planet.begin(), planet.end(), comparePoint);
        for(int j = 0; j < n - 1; j++)
        {
            long long cost = min(min(abs(planet[j].x - planet[j+1].x) , abs(planet[j].y - planet[j+1].y)), abs(planet[j].z - planet[j+1].z));
            edge temp;
            temp.from = planet[j].num;
            temp.to = planet[j+1].num;
            temp.cost = cost;
            pq.push(temp);
        }
    }

    while(!pq.empty())
    {
        edge current = pq.top();
        pq.pop();

        if(findParent(current.from) == findParent(current.to)) continue;
        
        unionParent(current.from, current.to);
        result += current.cost;
    }

    cout << result;
    return 0;
}