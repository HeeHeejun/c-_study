#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adjList;

int prim(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool visit[10001] = {false, };
    int result = 0;

    for(int i = 0; i < adjList[start].size(); i++)
    {
        pq.push({adjList[start][i].first, adjList[start][i].second});
    }
    visit[start] = true;

    while(!pq.empty())
    {
        int currentNode = pq.top().second;
        int currentCost = pq.top().first;
        pq.pop();

        if(visit[currentNode]) continue;

        visit[currentNode] = true;
        result += currentCost;
        for(int i = 0; i < adjList[currentNode].size(); i++)
        {
            int nextNode = adjList[currentNode][i].second;
            int nextCost = adjList[currentNode][i].first;
            if(!visit[nextNode]) pq.push({nextCost, nextNode});
        }
    }
    
    return result;
}

int main()
{
    int vertix, edge;
    cin >> vertix >> edge;

    adjList.resize(vertix + 1);
    for(int i = 0; i < edge; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        
        adjList[from].push_back({cost, to});
        adjList[to].push_back({cost, from});
    }

    cout << prim(1);
}