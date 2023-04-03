//(G5) tomato
// how many day all tomato is ripened?
// graph travel

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct coordinate
{
    int x, y, z;
};

int map[100][100][100];
bool visit[100][100][100] = {false};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dz[6] = {-1, 1, 0, 0, 0, 0};
int main()
{
    int row, col, height; cin >> col >> row >> height;
    queue<pair<coordinate, int>> q;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < row; j++)
        {
            for(int k = 0; k < col; k++)
            {
                cin >> map[j][k][i];
                if(map[j][k][i] == 1) {q.push({{j, k, i},0}); visit[j][k][i] = true;}
            }
        }
    }
    int max = 0;
    while (!q.empty())
    {
        pair<coordinate, int> current = q.front();
        q.pop();

        for(int i = 0; i < 6; i++)
        {
            coordinate next = {current.first.x + dx[i], current.first.y + dy[i], current.first.z + dz[i]};
            int cost = current.second + 1;
            if(next.x < 0 || next.y < 0 || next.z < 0 || next.x >= row || next.y >= col || next.z >= height || visit[next.x][next.y][next.z]) continue;
            if(map[next.x][next.y][next.z] != 0) continue;
            if(cost > max) max = cost;
            q.push({next, cost});
            visit[next.x][next.y][next.z] = true;
            map[next.x][next.y][next.z] = cost + 1;
        }
    }
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < row; j++)
        {
            for(int k = 0; k < col; k++)
            {
                if(map[j][k][i] == 0) {cout << -1; return 0;}
            }
        }
    }
    cout << max;
}