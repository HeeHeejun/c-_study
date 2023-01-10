//(골2) 트리의 지름
// 트리가 주어졌을 때, 트리의 지름을 출력
// dfs

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<vector<pair<int,int>>> adjList;

pair<int, int> treeDiameter(int node, int start);
int main()
{
    int node;
    cin >> node;
    adjList.resize(node+1);
    for(int i = 0; i < node; i++)
    {
        int start, end = 0, cost;
        cin >> start;
        while(end != -1)
        {
            cin >> end;
            if(end == -1) break;
            cin >> cost;
            adjList[start].push_back({end, cost});
        }
    }

    pair<int, int> end = treeDiameter(node, 1);
    pair<int, int> result = treeDiameter(node, end.first);

    cout << result.second;
}

pair<int, int> treeDiameter(int node, int start)
{
    stack<pair<int,int>> s;
    bool visit[node+1] = {false};
    pair<int, int> result = {start, 0};
    s.push({start,0});

    while(!s.empty())
    {
        pair<int, int> current = s.top();
        visit[current.first] = true;
        s.pop();

        if(result.second < current.second) result = current;

        for(int i = 0; i < adjList[current.first].size(); i++)
        {
            pair<int, int> next = adjList[current.first][i];
            if(!visit[next.first]) s.push({next.first, next.second + current.second});
        }
    }

    return result;
}