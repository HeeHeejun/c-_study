//일정 수색범위 안에 있는 아이템을 최대한 많이 먹을 수 있는 경우
//다익스트라 알고리즘

#include <iostream>
#include <queue>
#define INF 123456789

using namespace std;

int item[101];

vector<vector<pair<int, int>>> edge;
int vertix, edgeNum, scope;

void Dijkstra()
{
    int maxItem = 0;
    for(int i = 1; i <= vertix; i++)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int minCost[101];
        int visit[101];
        int start = i;

        for(int j = 1; j <= vertix; j++)
        {
            minCost[j] = INF;
            visit[j] = false;
        }

        minCost[start] = 0;
        pq.push({0, start});

        while (!pq.empty())
        {
            int currentNode = pq.top().second;
            int currentCost = pq.top().first;
            pq.pop();

            if(visit[currentNode]) continue;
            
            visit[currentNode] = true;

            for(int j = 0; j < edge[currentNode].size(); j++)
            {
                int nextNode = edge[currentNode][j].second;
                int nextCost = edge[currentNode][j].first;

                if(nextCost + currentCost > scope) continue;
                
                if(minCost[nextNode] > nextCost + currentCost)
                {
                    minCost[nextNode] = nextCost + currentCost;
                    pq.push({minCost[nextNode], nextNode});
                }
            }
        }

        int itemNum = 0;
        for(int j = 1; j <= vertix; j++)
        {
            if(minCost[j] <= scope)
            {
                itemNum += item[j];
            }
        }

        if(itemNum > maxItem){ maxItem = itemNum; }
    }
    cout << maxItem;
}

int main()
{
    cin >> vertix >> scope >> edgeNum;

    for(int i = 1; i <= vertix; i++)
    {
        cin >> item[i];
    }

    edge.resize(vertix + 1);

    for(int i = 0; i < edgeNum; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        edge[from].push_back({cost, to});
        edge[to].push_back({cost, from});
    }

    Dijkstra();
}