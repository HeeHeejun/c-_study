#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct tomato
{
    int x, y;
};

int main()
{
    int m, n;
    cin >> m >> n;

    int box[1001][1001];
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    queue<tomato> q;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int num;
            cin >> num;
            box[i][j] = num;
            if(box[i][j] == 1)
                q.push({j, i});
        }
    }

    while(!q.empty())
    {
        int correntX = q.front().x;
        int correntY = q.front().y;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nextX = correntX + dx[i];
            int nextY = correntY + dy[i];
            if(nextX > 0 && nextX <= m && nextY > 0 && nextY <= n)
            {
                if(box[nextY][nextX] == 0)
                {
                    box[nextY][nextX] = box[correntY][correntX] + 1;
                    q.push({nextX, nextY});
                }
            }
        }
    }

    int max = 1;
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(box[i][j] == 0)
            {
                cout << "-1";
                return 0;
            }
            else if(box[i][j] > max)
            {
                max = box[i][j];
            }
        }
    }

    cout << max -1;
    return 0;
}