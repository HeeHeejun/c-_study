#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void bfs(int node, int start);
void dfs(int node, int start);

vector<vector<int>> adjTable;

int main()
{
    int node, edge, start;
    cin >> node >> edge >> start;

    adjTable.resize(node + 1);
    for(int i = 0; i < edge; i++)
    {
        int tempStart, tempEnd;
        cin >> tempStart >> tempEnd;
        adjTable[tempStart].push_back(tempEnd);
        adjTable[tempEnd].push_back(tempStart);
    }

    for(int i = 1; i < node + 1; i++)
    {
        
        sort(adjTable[i].begin(), adjTable[i].end());
    }

    dfs(node,start);
    bfs(node,start);
    
    return 0;
}

void bfs(int node, int start)
{
    queue<int> q;
    vector<int> path;
    bool visit[node + 1] = {false};

    q.push(start);
    visit[start] = true;

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        path.push_back(current);

        for(int i = 0; i < adjTable[current].size(); i++)
        {
            int next = adjTable[current][i];
            if(!visit[next])
            {
                visit[next] = true;
                q.push(next);
            }
        }
    }

    for(int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << "\n";
}

void dfs(int node, int start)
{
    stack<int> s;
    bool visit[node + 1] = {false};
    vector<int> path;

    s.push(start);

    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        if(visit[current]) continue;

        path.push_back(current);
        visit[current] = true;

        for(int i = adjTable[current].size() - 1; i >= 0; i--)
        {
            int next = adjTable[current][i];
            if(!visit[next])
            {
                s.push(next);
            }
        }
    }

    for(int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << "\n";
}