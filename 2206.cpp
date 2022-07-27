#include <iostream>
#include <queue>
using namespace std;

char matrix[1001][1001];
bool visit[1001][1001][2];

struct Data
{
    int x;
    int y;
    bool isBreak;
    int cost;
};

void shortestPath(int lastColumn, int lastRow)
{
    queue<Data> q; 
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    q.push({1,1,false, 1});
    visit[1][1][0] = true;
    visit[1][1][1] = true;

    while(!q.empty())
    {
        Data current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;
        bool isBreak = current.isBreak;
        int cost = current.cost;

        if(x == lastColumn && y == lastRow)
        {
            cout << cost;
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if(nextX == 0 || nextY == 0 || nextX == lastColumn + 1 || nextY == lastRow + 1)
            {
                continue;
            }

            if((isBreak && visit[nextX][nextY][1]) || (!isBreak && visit[nextX][nextY][0]))
            {
                continue;
            }
                        
            if(matrix[nextX][nextY] == '0')
            {
                if(isBreak)
                {
                    visit[nextX][nextY][1] = true;
                    q.push({nextX, nextY, true, cost + 1});
                }
                else
                {
                    visit[nextX][nextY][0] = true;
                    q.push({nextX, nextY, false, cost + 1});
                }                    
            }
            else
            {
                if(isBreak)
                {
                    continue;
                }
                else
                {  
                    visit[nextX][nextY][1] = true;
                    q.push({nextX, nextY, true, cost + 1});
                }
            }
        }
    }
    cout << -1;    
}


int main()
{
    int row, column;
    cin >> column >> row;

    for(int i = 1; i <= column; i++)
    {
        for(int j = 1; j <= row; j++)
        {
            cin >> matrix[i][j];
            visit[i][j][0] == false;
            visit[i][j][1] == false;
        }
    }
    shortestPath(column, row);
}