// (골1) 구슬 탈출 2
// 상하좌우 판을 기울여 빨간 구슬을 구멍에 몇번 만에 탈출할 수 있는지 구하라
// 그래프 탐색, bfs

#include <iostream>
#include <queue>
using namespace std;

struct position
{
    int redX, redY, blueX, blueY, count, direction = -100;
};

char matrix[10][10];

int main()
{
    int row, col;
    position start;
    cin >> row >> col;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j] == 'R') {start.redX = i; start.redY = j;}
            else if(matrix[i][j] == 'B') {start.blueX = i; start.blueY = j;}
        }
    }

    queue<position> move;
    int escapeCount = 0, currentCount = 0;
    start.count = 0;
    move.push(start);

    while (!move.empty())
    {
        position current = move.front();
        move.pop();        
        if(current.count > 10) break;
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {-1, 0, 1, 0};

        current.count++;
        for(int i = 0; i < 4; i++)
        {
            bool redStop = false, blueStop = false, redEscape = false, blueEscape = false;
            position next = current;
            if(abs(i - current.direction) == 2) continue;
            next.direction = i;
            while(!(redStop && blueStop))
            {
                redStop = matrix[next.redX + dx[i]][next.redY + dy[i]] == '#' || (next.redX + dx[i] == next.blueX && next.redY + dy[i] == next.blueY);
                blueStop = matrix[next.blueX + dx[i]][next.blueY + dy[i]] == '#' || (next.redX == next.blueX + dx[i] && next.redY == next.blueY + dy[i]);
                redEscape = (matrix[next.redX + dx[i]][next.redY + dy[i]] == 'O') || redEscape;
                blueEscape = (matrix[next.blueX + dx[i]][next.blueY + dy[i]] == 'O') || blueEscape;
                
                if(redEscape && !blueEscape){escapeCount = next.count;}
                else if(redEscape && blueEscape){ escapeCount = -1;}

                if(!redStop)
                {
                    next.redX += dx[i]; next.redY += dy[i];
                }
                if(!blueStop)
                {
                    next.blueX += dx[i]; next.blueY += dy[i];
                }
            }

            if(blueEscape && !redEscape) continue;
            else if(blueEscape && redEscape) continue;

            if(next.redX == current.redX && next.redY == current.redY 
                && next.blueX == current.blueX && next.blueY == current.blueY) continue;            
            move.push(next);
        }
        currentCount = current.count;
        if(escapeCount > 0) {break;}
    }
    if(escapeCount > 0 && currentCount <= 10) {cout << currentCount;}
    else cout << -1;
}