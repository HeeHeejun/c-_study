#include <iostream>
#include <queue>

using namespace std;
int bfs(int start,int end);
int main()
{
    int start, end;
    cin >> start >> end;

    cout << bfs(start, end);
}

int bfs(int start, int end)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    bool visit[100001] = {false};
    int dx[3] = {-1, 1, 0};
    visit[start] = true;
    while(!q.empty())
    {
        int current =  q.front().first;
        int currentCost = q.front().second;
        q.pop();
        
        if(current == end) return currentCost;
        for(int i = 0; i < 3; i++)
        {
            int next = current + dx[i];
            if(i == 2) next *= 2;
            int nextCost = currentCost + 1;

            if(next >= 0 && next <= 100000 && !visit[next])
            { 
                visit[next] = true;
                q.push({next, nextCost}); 
            }
        }
    }

    return -1;
}