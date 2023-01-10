//(��3) ��Ȧ
//���� ������ �����ϴ� �׷������� ������� �ٽ� ���ƿ��� ��� �ð��� ���� ������ �ƴ��� ���
//���� ����

#include <iostream>
#include <vector>
#define INF 10001

using namespace std;
vector<vector<pair<int,int>>> adjList;
vector<int> cost;
bool bellManFord(int node, int edge, int minusEdge);
int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int node, edge, minusEdge;
        cin >> node >> edge >> minusEdge;
        adjList.resize(node+1);
        cost.resize(node+1, INF);

        for(int i = 0; i < edge; i++)
        {
            int start, end, cost;
            cin >> start >> end >> cost;
            adjList[start].push_back({end, cost});
            adjList[end].push_back({start, cost});
        }

        for(int i = 0; i < minusEdge; i++)
        {
            int start, end, cost;
            cin >> start >> end >> cost;
            adjList[start].push_back({end, -cost});
        }
        
        if(bellManFord(node, edge, minusEdge)) cout << "YES\n";
        else cout << "NO\n";

        adjList.clear();
        cost.clear();
    }
    
}

bool bellManFord(int node, int edge, int minusEdge)
{
    cost[1] = 0;
    for(int i = 1; i <= node; i++)
    {
        for(int j = 1; j <= node; j++)
        {
            for(int k = 0; k < adjList[j].size(); k++)
            {
                int next = adjList[j][k].first;
                int nextCost = adjList[j][k].second;

                if(cost[next] > cost[j] + nextCost)
                {
                    cost[next] = cost[j] + nextCost;
                    if(i == node) return true;
                }
            }
        }
    }

    if(cost[1] < 0) return true;

    return false;
}