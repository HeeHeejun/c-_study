// (골1) 비숍
// 체스판이 주어지면 서로 잡히지 않는 위치에 비숍을 놓을 수 있는 경우의 수 출력
// 백트래킹

#include <iostream>
#define black 0
#define white 1

using namespace std;

bool map[10][10] = {false};
bool leftToRight[20];
bool rightToLeft[20];
int result[2];
int n;

void place(int x, int y, int count, int color);

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    place(0, 0, 0, black);
    place(0, 1, 0, white);

    cout << result[black] + result[white];
}

void place(int x, int y, int count, int color)
{
    if(y >= n)
    {
        x++;
        if(!(y % 2)) y = 1;
        else y = 0;
    }
    if(x >= n)
    {
        if(count > result[color]) result[color] = count;
        return;
    }

    if(map[x][y] && !leftToRight[y - x + n - 1] && !rightToLeft[x+y])
    {
        leftToRight[y - x + n - 1] = rightToLeft[x + y] = true;
        place(x, y + 2, count + 1, color);
        leftToRight[y - x + n - 1] = rightToLeft[x + y] = false;
    }
    place(x, y + 2, count, color);
}