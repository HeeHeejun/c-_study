#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

bool visit[102][102] = {false, };
int count = 0;

void bfs(int x, int y, char (&newGrid)[102][102])
{
    queue<pair<int, int>> que;
    que.push({x,y});

    char color = newGrid[x][y];
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    while(!que.empty())
    {
        pair<int, int> point = que.front();
        que.pop();

        if(visit[point.first][point.second]) continue;
        visit[point.first][point.second] = true;

        for(int i = 0; i < 4; i++)
        {
            if(newGrid[point.first - dx[i]][point.second - dy[i]] != color) continue;
            que.push({point.first - dx[i], point.second - dy[i]});
        }
    }
    count++;
}

bool search(int size, char (&newGrid)[102][102])
{
    bool ischange = false;
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            if(!visit[i][j])
            {
                bfs(i,j, newGrid);
                ischange = true;
            }
        }
    }
    return ischange;
}

int main()
{
    int size;
    cin >> size;

    char grid[102][102] = {0, };
    char blindGrid[102][102] = {0, };

    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= size; j++)
        {
            char color;
            cin >> color;
            grid[i][j] = color;
            if(color != 'B')
            {
                blindGrid[i][j] = 'R';
            }
            else
            {
                blindGrid[i][j] = color;
            }
        }
    }

    while(!search(size, grid)){}
    cout << count << " ";
    memset(visit, false, sizeof(visit));
    count = 0;
    while(!search(size, blindGrid)){}
    cout << count;
}