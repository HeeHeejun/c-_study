//(골5) 다각형의 면적
//좌표가 주어진 다각형의 넓이를 구하라
//신발끈 공식

#include <iostream>
#include <math.h>
double coordinate[10000][2];
using namespace std;
int main()
{
    int n; cin >> n;
    for(int i= 0; i < n; i++)
    {
        cin >> coordinate[i][0] >> coordinate[i][1];
    }
    double result = 0;
    for(int i = 0; i < n - 1; i++)
    {
        result += (coordinate[i][0] * coordinate[i+1][1]);
        result -= (coordinate[i][1] * coordinate[i+1][0]);
    }
    result += (coordinate[n-1][0] * coordinate[0][1]);
    result -= (coordinate[n-1][1] * coordinate[0][0]);

    result = round((abs(result)/2.0)*10) / 10.0;
    printf("%0.1lf",result);
}