//(실1) 1로 만들기 
// X가 3으로 나누어 떨어지면 3으로 나누고, x가 2로 나누어지면 2로 나눈다, -1을 한다. 주어진 수에 대해 1로 만드는 최소의 횟수를 출력
// dp

#include <iostream>
#define INF 200000000
using namespace std;

int dp[1000001] = {0};
int parent[1000001] = {0};
int main()
{
    int n; cin >> n;
    for(int i = 2; i <= n; i++)
    {
        int dividThree = INF, dividTwo = INF, minusOne = INF;
        int min = INF, currentParent = 0;
        if(i % 3 == 0) dividThree = dp[i / 3];
        if(i % 2 == 0) dividTwo = dp[i / 2];
        minusOne = dp[i - 1];
        
        if(minusOne > dividTwo)
        {
            min = dividTwo;
            currentParent = i / 2;
        }
        else
        {
            min = minusOne;
            currentParent = i - 1;
        }

        if(min > dividThree)
        {
            min = dividThree;
            currentParent = i / 3;
        }
        dp[i] = min + 1;
        parent[i] = currentParent;
    }

    cout << dp[n] << "\n";
    for(int i = n; i != 0; i = parent[i])
    {
        cout << i << " ";
    }
}