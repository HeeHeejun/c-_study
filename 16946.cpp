// (골2) 벽 부수고 이동하기4
// 벽이 있는 곳에 벽을 부수고 이동할 수 있는 총 칸의 개수를 출력하라.
// bfs

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <set>

using namespace std;

bool map[1000][1000] = {false};
bool visit[1000][1000] = {false};
int result[1000][1000] = {0};
int group[1000][1000] = {0};
vector<int> groupCount;
int groupNum = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void countCell(int row, int col);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col; cin >> row >> col;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0;  j < col; j++)
        {
            char temp; cin >> temp;
            map[i][j] = temp - '0';
            result[i][j] = temp - '0';
        }
    }

    countCell(row, col);
}

void countCell(int row, int col)
{
    queue<pair<int, int>> travel;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            int count = 0;
            if(!map[i][j] && !visit[i][j])
            {
                travel.push({i,j});
                visit[i][j] = true;
                group[i][j] = groupNum;
                count++;
                //cout << "            " << i << j << "\n";
                while (!travel.empty())
                {
                    pair<int, int> current = travel.front();
                    travel.pop();

                    for(int k = 0; k < 4; k++)
                    {
                        pair<int, int> next = {current.first + dx[k], current.second + dy[k]};

                        if(next.first < 0 || next.second < 0 || next.first >= row || next.second >= col) continue;
                            //cout << next.first << next.second << "\n";
                            //cout << map[next.first][next.second] << visit[next.first][next.second] << group[next.first][next.second] << "\n";
                        if(!map[next.first][next.second] && !visit[next.first][next.second] && group[next.first][next.second] == 0)
                        {
                            visit[next.first][next.second] = true;
                            group[next.first][next.second] = groupNum;
                            travel.push(next);
                            count++;
                        }
                    }
                }
                groupNum++;
                groupCount.push_back(count);
            }
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(map[i][j])
            {
                int cell = 1;
                set<int> s;
                for(int k = 0; k < 4; k++)
                {
                    pair<int, int> next = {i + dx[k], j + dy[k]};

                    if(next.first < 0 || next.second < 0 || next.first >= row || next.second >= col || map[next.first][next.second]) continue;
                    if(s.find(group[next.first][next.second]) == s.end())
                    {
                        cell += groupCount[group[next.first][next.second]];
                        s.insert(group[next.first][next.second]);
                    }
                }
                result[i][j] = cell % 10;
            }
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j <col; j++)
        {
            cout << result[i][j];
        }
        cout << "\n";
    }
}
