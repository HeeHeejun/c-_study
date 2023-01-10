//(��5) �ּҺ�� ���ϱ�
// A���ÿ��� B���� ���� ���µ� �ɸ��� �ּ� ��� ���
// ���ͽ�Ʈ��

#include <iostream>
#include <queue>
#include <queue>
#define INF 100000000

using namespace std;

vector<vector<pair<int,int>>> adjList;

int leastCost(int node, int start, int end);

int main()
{
    int city, bus;
    cin >> city >> bus;

    adjList.resize(city+1);
    for(int i = 0; i < bus; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        adjList[start].push_back({cost, end});
    }

    int start, end;
    cin >> start >> end;

    int result = leastCost(city, start, end);
    cout << result;
}

int leastCost(int node, int start, int end)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,start});

    int visit[node+1] = {false};
    int cost[node+1];
    fill_n(cost, node+1, INF);
    cost[start] = 0;
    while(!q.empty())
    {
        int current = q.top().second;
        int currentCost = q.top().first;
        q.pop();
        visit[current] = true;

        if(end == current) return currentCost;
        
        for(int i = 0; i < adjList[current].size(); i++)
        {
            int next = adjList[current][i].second;
            int nextCost = adjList[current][i].first + currentCost;
            if(!visit[next] && nextCost < cost[next])
            {
                cost[next] = nextCost;
                q.push({nextCost, next});
            }
        }
    }

    return -1;
}