// (골4) RGB거리 2
// 자신의 양 옆과 같은 색이 존재하지 않게 모든 집에 색을 칠하는 최소 비용을 구하라
// DP

#include <iostream>
#define INF 200000000
using namespace std;
int RGB[3][1001] = {0};
int minCost[3][1001] = {0}; 

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int r, g, b; cin >> r >> g >> b;
        RGB[0][i] = r;
        RGB[1][i] = g;
        RGB[2][i] = b; 
    }
    int result = INF;
    for(int i = 0; i < 3; i++)
    {
        int one = i, two = (i+1)%3, thr = (i+2)%3;
        minCost[one][1] = RGB[one][1];
        minCost[two][1] = minCost[thr][1] = INF;
        for(int j = 2; j <= n; j++)
        {
            minCost[one][j] = min(minCost[two][j-1], minCost[thr][j-1]) + RGB[one][j];
            minCost[two][j] = min(minCost[one][j-1], minCost[thr][j-1]) + RGB[two][j];
            minCost[thr][j] = min(minCost[one][j-1], minCost[two][j-1]) + RGB[thr][j];
        }
        result = min(result, min(minCost[two][n], minCost[thr][n]));
    }
    cout << result;
}