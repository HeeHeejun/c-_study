//백준 1504번 특정한 최단 경로
//특정 정점 두 점을 지나는 최단거리

#include <iostream>
#include <queue>
#define INF 87654321
using namespace std;

vector<vector<pair<int, int>>> edge;

int Dijkstra(int start, int end, int size)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    
    int cost[size + 1];
    for(int i = 1; i <= size; i++)
    {
        cost[i] = INF;
    }

    que.push({0, start});
    cost[start] = 0;

    while(!que.empty())
    {   
        int currentCost = que.top().first;
        int currentNode = que.top().second;
        que.pop();

        if(currentNode == end)
        {
            break;
        }

        if(currentCost > cost[currentNode]) continue;

        for(int i = 0; i < edge[currentNode].size(); i++)
        {
            int nextCost = edge[currentNode][i].first;
            int nextNode = edge[currentNode][i].second;
            if(cost[nextNode] > nextCost + currentCost)
            {
                cost[nextNode] = nextCost + currentCost;
                que.push({cost[nextNode], nextNode});
            }
        }
    }

    return cost[end];
}

int main()
{
    int nodeNum, edgeNum, firstNode, secondNode;
    cin >> nodeNum >> edgeNum;
    edge.resize(nodeNum + 1);

    for(int i = 0; i < edgeNum; i++)
    {
        int start, last, cost;
        cin >> start >> last >> cost;
        edge[start].push_back({cost, last});
        edge[last].push_back({cost, start});
    }
    cin >> firstNode >> secondNode;
    
    long long start1 = Dijkstra(1, firstNode, nodeNum);
    long long start2 = Dijkstra(1, secondNode, nodeNum);
    long long between = Dijkstra(firstNode, secondNode, nodeNum);
    long long last2 = Dijkstra(firstNode, nodeNum, nodeNum);
    long long last1 = Dijkstra(secondNode, nodeNum, nodeNum);
    long long course1 = start1 + between + last1;
    long long course2 = start2 + between + last2;

    if(start1 == INF || between == INF || last1 == INF)
    {
        course1 = INF;
    }

    if(start2 == INF || between == INF || last2 == INF)
    {
        course2 = INF;
    }
    
    if(course1 == INF && course2 == INF)
    {
        cout << -1;
        return 0;
    }

    if(course1 < course2)
    {
        if(course1 >= INF){ cout << -1;}
        cout << course1;
    }
    else
    {
        if(course2 >= INF){ cout << -1;}
        cout << course2;
    }
}

