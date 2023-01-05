#include <iostream>
#include <queue>
#include <vector>
#define INF 200000000


using namespace std;

vector<vector<int>> adjlist;
int dijkstra(int start);

int main()
{
    int n, adge;
    cin >> n >> adge;
    adjlist.resize(n + 1);
    for(int i = 0; i < adge; i++)
    {
        int start, end;
        cin >> start >> end;
        adjlist[start].push_back(end);
        adjlist[end].push_back(start);
    }

    int min = INF;
    int min_node = 0;
    for(int i = 1; i <= n; i++)
    {
        int temp = dijkstra(i);
        if(temp < min) 
        {
            min = temp;
            min_node = i;
        }
    }

    cout << min_node;
}

int dijkstra(int start)
{
    queue<pair<int,int>> q;
    int cost[adjlist.size()];
    for(int i = 0; i < adjlist.size(); i++){ cost[i] = INF; }
    cost[start] = 0;
    q.push({start, 0});

    while (!q.empty())
    {
        int current = q.front().first;
        int currentCost = q.front().second;
        q.pop();

        for(int i = 0; i < adjlist[current].size(); i++)
        {
            int next = adjlist[current][i];
            int nextCost = currentCost + 1;
            if(cost[next] > nextCost && cost[next] == INF)
            {
                cost[next] = nextCost;
                q.push({next, nextCost});
            }
        }
    }

    int sum = 0;
    for(int i = 1; i < adjlist.size(); i++)
    { 
        sum += cost[i];
    }

    return sum;
}