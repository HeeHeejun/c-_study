//(실2) 연결요소의 개수
// 몇 개의 그래프로 이루어 져 있는지 출력
// bfs

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> adjList;
int graphCount(int node);
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

    int result = graphCount(node);
    cout << result;
}

int graphCount(int node)
{
    int result = 0;
    bool visit[node + 1] = {false};
    bool isEnd = false;
    while(!isEnd)
    {
        int start = 0;
        for(int i = 1; i <= node; i++)
        {
            if(!visit[i]) start = i;
        }

        if(start == 0) {isEnd = true; break;}

        queue<int> q;
        q.push(start);
        visit[start] = true;
        while(!q.empty())
        {
            int current = q.front();
            q.pop();

            for(int i = 0; i < adjList[current].size(); i++)
            {
                int next = adjList[current][i];
                if(!visit[next]) {q.push(next); visit[next] = true;}
            }
        }
        result++;
    }
    return result;
}

