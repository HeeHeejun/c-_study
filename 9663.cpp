//(골4) n-queen
//퀸 n개가 서로 공격할 수 없는 위치에 놓는 경우의 수를 출력
//백트래킹

#include <iostream>
using namespace std;

int map[15];
int replaceQueen(int n, int current);
int main()
{
    //같은 줄에는 하나만 --> 한줄에 하나만 나타내면됨
    //한줄의 번호에 다른 번호가 존재하면 안댐.
    //대각선 즉, [a][b]에 있고 퀸이 [i][j] 이면  a-i = b-j이면 대각선임.
    // i-a = b-j이면 안댐.
    int n;
    cin >> n;
    
    int result = replaceQueen(n, 0);
    cout << result;
}

int replaceQueen(int n, int current)
{
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        map[current] = i;
        bool isPromise = true;
        for(int j = 0; j < current; j++)
        {
            if(map[current] == map[j] || abs(current - j) == abs(map[current] - map[j])) {isPromise = false; break;}
        }
        if(!isPromise) continue;
        if(current == n - 1) {result++; continue;}
        result += replaceQueen(n, current+1);
    }

    return result;
}