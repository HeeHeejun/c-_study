//(골4) 연구소
//바이러스가 퍼지게 하지 않게하는 3개의 벽을 세울 경우, 최대의 안전구역의 개수를 구하라.
//그래프 탐색

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[8][8];
int copyMap[8][8];
bool visit[8][8] = {false};
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int row, col;
pair<int, int> wall[3];
vector<pair<int, int>> canWall, birus;
int countSafe();
int main()
{
    //입력
    cin >> row >> col;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 2) birus.push_back({i, j});
            else if(map[i][j] == 0) canWall.push_back({i, j});
        }
    }

    //벽세우기
    int result = 0;
    for(int i = 0; i < canWall.size(); i++)
    {
        for(int j = 0; j < canWall.size(); j++)
        {
            for(int k = 0; k < canWall.size(); k++)
            {
                if(i >= j || i >= k || j >= k) continue;
                wall[0] = canWall[i];
                wall[1] = canWall[j];
                wall[2] = canWall[k];
                result = max(result, countSafe());
            }
        }
    }

    cout << result;
}

int countSafe()
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            copyMap[i][j] = map[i][j];
            visit[i][j] = false;
        }
    }
    for(int i = 0; i < 3; i++){copyMap[wall[i].first][wall[i].second] = 1;} 

    int result = 0;
    
    for(auto it = birus.begin(); it != birus.end(); it++)
    {
        if(visit[(*it).first][(*it).second]) continue;
        visit[(*it).first][(*it).second] = true;

        queue<pair<int, int>> travel;
        travel.push(*it);

        while (!travel.empty())
        {
            pair<int, int> current = travel.front();
            travel.pop();

            for(int i = 0; i < 4; i++)
            {
                pair<int, int> next = {current.first + dx[i], current.second + dy[i]};
                if(next.first < 0 || next.second < 0 || next.first >= row || next.second >= col || visit[next.first][next.second]) continue;
                if(copyMap[next.first][next.second] != 1)
                {
                    visit[next.first][next.second] = true;
                    copyMap[next.first][next.second] = 2;
                    travel.push(next);
                }
            }
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(copyMap[i][j] == 0) result++;
        }
    }

    return result;
}