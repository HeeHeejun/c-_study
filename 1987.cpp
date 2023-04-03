//(골4) 알파벳
//첫번째 에서 시작해서 같은 알파벳을 지나지 않는 최대의 거리를 구하라
//그래프 탐색

#include <iostream>

using namespace std;
char map[20][20];
bool visit[20][20] = {false};
bool alphabet[26] = {false};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int row, col, count = 0, maxCount = 0;

void backTracking(int startX, int startY);

int main()
{
    cin >> row >> col;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> map[i][j];
        }
    }
    backTracking(0,0);

    cout << maxCount;
}

void backTracking(int startX, int startY)
{
    count++;
    alphabet[map[startX][startY]] = true;
    //cout <<startX << startY<< map[startX][startY] << "\n";
    int result;
    bool isGo = false;
    bool isBack = false;
    for(int i = 0; i < 4; i++)
    {
        int nextX = startX + dx[i];
        int nextY = startY + dy[i];
        
        if(nextX < 0 || nextY < 0 || nextX >= row || nextY >= col) continue;
        //cout <<nextX << nextY<< map[nextX][nextY] << "\n";
        if(!alphabet[map[nextX][nextY]])
        {
            isGo = true; 
            //out <<nextX << nextY<< map[nextX][nextY] << "\n";
            backTracking(nextX, nextY);
        }
    }
    
    alphabet[map[startX][startY]] = false;
    count--;
    if(!isGo) 
    {
        if(maxCount < count + 1) maxCount = count + 1;
    }
    return;
}