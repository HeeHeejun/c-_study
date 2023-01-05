#include <iostream>
#include <queue>

using namespace std;
int map[101][101];
void maze(int lastX, int lastY);
int main()
{
    int x, y;
    cin >> x >> y;
    for(int i = 1; i <= x; i++)
    {
        for(int j = 1; j <= y; j++)
        {
            char temp;
            cin >> temp;
            map[i][j] = temp - '0';
        }
    }

    maze(x,y);
}

void maze(int lastX, int lastY)
{
    queue<pair<int,int>> q;
    q.push({1,1});

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while(!q.empty())
    {
        pair<int, int> current = q.front();
        int cost = map[current.first][current.second];
        q.pop();

        if(current.first == lastX && current.second == lastY) break;

        for(int i = 0; i < 4; i++)
        {
            pair<int, int> next = {current.first + dx[i], current.second + dy[i]};
            if(next.first >= 1 && next.second >= 1 && next.first <= lastX && next.second <= lastY && map[next.first][next.second] == 1)
            {
                if(next.first == 1 && next.second == 1) continue;
                map[next.first][next.second] = cost + 1;
                q.push(next);
            }
        }
    }

    cout << map[lastX][lastY];
}