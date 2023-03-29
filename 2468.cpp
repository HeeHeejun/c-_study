//(실1) 안전 영역
// 숫자보다 작은 구역이 잠길 경우, 안전영역의 개수의 최대값을 구하라
// 그래프 탐색

#include <iostream>
#include <queue>
#include <vector>
#define INF 101
using namespace std;

int map[100][100];
bool visit[100][100][101];
int n, maxHeight =  0, minHeight = INF;
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};

int countSafe(int dangerHeight);
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] > maxHeight) maxHeight = map[i][j];
            else if(map[i][j] <= minHeight) minHeight = map[i][j];
        }
    }

    int result = 1;
    for(int i = minHeight; i < maxHeight; i++)
    {
        result = max(result, countSafe(i));
    }

    cout << result;
}

int countSafe(int dangerHeight)
{
    int result = 0;
    vector<pair<int, int>> canStart;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(dangerHeight < map[i][j]) canStart.push_back({i,j});
        }
    }

    for(auto it = canStart.begin(); it != canStart.end(); it++)
    {
        if(visit[(*it).first][(*it).second][dangerHeight]) continue;
        visit[(*it).first][(*it).second][dangerHeight] = true;

        queue<pair<int, int>> travel;
        travel.push(*it);
        result++;
        while (!travel.empty())
        {
            pair<int, int> current = travel.front();
            travel.pop();
            for(int i = 0; i < 4; i++)
            {
                pair<int, int> next = {current.first + dx[i], current.second + dy[i]};
                if(next.first < 0 || next.second < 0 || next.first >= n || next.second >= n ) continue;
                if(visit[next.first][next.second][dangerHeight] || map[next.first][next.second] <= dangerHeight) continue;
                travel.push(next);
                visit[next.first][next.second][dangerHeight] = true;
            }
        }
    }

    return result;
}