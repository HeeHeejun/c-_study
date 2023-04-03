// (S1) knight movement
// how many movement of knight can go wanted place
// graph travel

#include <iostream>
#include <queue>

using namespace std;
struct coordinate
{
    int x, y, cost;
};

bool visit[300][300] = {false};
int dx[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
int dy[8] = {-1, 1, 2, -2, -1, 1, 2, -2};
int main()
{
    int testCase; cin >> testCase;
    while (testCase--)
    {
        int n, startX, startY, endX, endY; cin >> n >> startX >> startY >> endX >> endY;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                visit[i][j] = false;
            }
        }
        
        queue<coordinate> q;
        q.push({startX, startY, 0});
        visit[startX][startY] = true;
        if(startX == endX && startY == endY) {cout << 0 << "\n"; continue;}

        while (!q.empty())
        {
            bool isStopTravel = false;
            coordinate current = q.front();
            q.pop();

            for(int i = 0; i < 8; i++)
            {
                coordinate next = {current.x + dx[i], current.y + dy[i], current.cost + 1};
                if(next.x < 0 || next.y < 0 || next.x >= n || next.y >= n || visit[next.x][next.y]) continue;
                if(next.x == endX && next.y == endY) {isStopTravel = true; count = next.cost; break;}
                q.push(next);
                visit[next.x][next.y] = true;
            }

            if(isStopTravel) break;
            
        }
        cout << count << "\n";
    }
}