#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adjList;

int virus(int node);
int main()
{
    int node, edge;
    cin >> node >> edge;
    adjList.resize(node+1);

    for(int i = 0; i < edge; i++)
    {
        int start, end;
        cin >> start >> end;
        adjList[start].push_back(end);
        adjList[end].push_back(start);
    }

    int result = virus(node);

    cout << result;
}

int virus(int node)
{
    bool visit[node+1] = {false};
    queue<int> q;
    q.push(1);
    visit[1] = true;
    int computer = 0;

    while(!q.empty())
    {
        int current = q.front();
        q.pop();

        for(auto next = adjList[current].begin(); next != adjList[current].end(); next++)
        {
            if(!visit[*next])
            {
                q.push(*next);
                visit[*next] = true;
                computer++;
            }
        }
    }

    return computer;
}