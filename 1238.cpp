// (골3) 파티
// 학생 중에 마을에 오고가는 시간이 가장 오래걸리는 학생의 시간을 출력
// 다익스트라

#include <iostream>
#include <queue>
#include <vector>
#define INF 200000000

using namespace std;
int longestPath(int village, int destination);
int dijkstra(int village, int start, int destination);
void dijkstra(int village, int start, vector<int>& list);

vector<vector<pair<int, int>>> adjList;

int main()
{
    int village, road, destination;
    cin >> village >> road >> destination;

    adjList.resize(village+1);

    for(int i = 0; i < road; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        adjList[start].push_back({cost, end});
    }

    int result = longestPath(village, destination);
    cout << result;
}

int longestPath(int village, int destination)
{
    int result = 0;
    vector<int> comeback(village + 1, INF);
    dijkstra(village, destination, comeback);
    for(int i = 1; i <= village; i++)
    {
        int temp = dijkstra(village, i, destination) + comeback[i];
        if(temp > result) result = temp;
    }

    return result;
}

int dijkstra(int village, int start, int destination)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, start});
    bool visit[village+1] = {};

    while(!q.empty())
    {
        int current = q.top().second;
        int currentCost = q.top().first;
        q.pop();
        if(visit[current]) continue;
        visit[current] = true;
        if(current == destination) return currentCost;

        for(int i = 0; i < adjList[current].size(); i++)
        {
            int next = adjList[current][i].second;
            int nextCost = adjList[current][i].first + currentCost;
            if(!visit[next]){ q.push({nextCost, next}); }
        }
    }

    return INF;
}

void dijkstra(int village, int start, vector<int>& list)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, start});
    bool visit[village+1] = {};
    list[start] = 0;

    while (!q.empty())
    {
        int current = q.top().second;
        int currentCost = q.top().first;
        q.pop();
        if(visit[current]) continue;
        visit[current] = true;

        for(int i = 0; i < adjList[current].size(); i++)
        {
            int next = adjList[current][i].second;
            int nextCost = adjList[current][i].first + currentCost;
            if(!visit[next] && list[next] > nextCost)
            {
                list[next] = nextCost;
                q.push({nextCost, next});
            }
        }
    }
}
