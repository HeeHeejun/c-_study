//(골5) 내려가기
// 현재위치에서 대각선과 아래로만 이동할 수 있는데, 이렇게 내려갈 때 최대의 점수와 최소의 점수를 출력
//dp

#include <iostream>

using namespace std;
int window[3][3] = {};
void max_min(int n);
int main()
{
    int n;
    cin >> n;
    max_min(n);
}

void max_min(int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> window[0][0] >> window[0][1] >> window[0][2];
        if(i == 0)
        {
            for(int j = 0; j < 3; j++)
            {
                window[1][j] = window[0][j];
                window[2][j] = window[0][j];            
            }
            continue;
        }
        int maxFirst = window[1][0], maxSecond = window[1][1], maxLast = window[1][2];
        int minFirst = window[2][0], minSecond = window[2][1], minLast = window[2][2];
        for(int j = 0; j < 3; j++)
        {
            if(j == 0)
            {
                window[1][j] = window[0][j] + max(maxFirst, maxSecond);
                window[2][j] = window[0][j] + min(minFirst, minSecond);
            }
            else if(j == 2)
            {
                window[1][j] = window[0][j] + max(maxSecond, maxLast);
                window[2][j] = window[0][j] + min(minSecond, minLast);
            }
            else
            {
                window[1][j] = window[0][j] + max(maxFirst, max(maxSecond, maxLast));        
                window[2][j] = window[0][j] + min(minFirst, min(minSecond, minLast));
            }
        }
        //cout << window[1][0] << window[1][1] << window[1][2] << "\n";
    }
    cout << max(window[1][0], max(window[1][1], window[1][2])) << " " << min(window[2][0], min(window[2][1], window[2][2]));
}