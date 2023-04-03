//(S2) island of number
// up, down, left, right, cross -> one island // count of island in map 
//Graph travel

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
bool map[50][50] = {false};
bool visit[50][50] = {false};
int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};
int countIsland(vector<pair<int, int>>& land, int row, int col);
int main()
{
    int row = -1, col = -1; 
    while (!(row == 0 && col == 0))
    {
        cin >> col >> row;
        if(row == 0 && col == 0) break;
        vector<pair<int, int>> land;
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j <  col; j++)
            {
                cin >> map[i][j];
                if(map[i][j]) land.push_back({i,j});
                visit[i][j] = false;
            }
        }

        cout << countIsland(land, row, col) << "\n";
    }
}

int countIsland(vector<pair<int, int>>& land, int row, int col)
{
    int count = 0;
    for(auto start = land.begin(); start != land.end(); start++)
    {
        if(visit[(*start).first][(*start).second]) continue;
        visit[(*start).first][(*start).second] = true;
        queue<pair<int,int>> q;
        q.push(*start);

        while(!q.empty())
        {
            pair<int, int> current = q.front();
            q.pop();

            for(int i = 0; i < 8; i++)
            {
                pair<int, int> next = {current.first + dx[i], current.second + dy[i]};
                if(next.first < 0 || next.second < 0 || next.first >= row || next.second >= col || visit[next.first][next.second]) continue;
                if(map[next.first][next.second])
                {
                    visit[next.first][next.second] = true;
                    q.push(next);
                }
            }
        }
        count++;
    }
    return count;
}
