#include <iostream>
#define INF 200000000

using namespace std;
int dp[1000001] = {};
int makeone(int n);
int main()
{
    int n;
    cin >> n;
    int result = makeone(n);
    cout << result;
}

int makeone(int n)
{
    dp[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        int one = INF, two = INF, three = INF;
        if(i % 3 == 0) one = dp[i/3];
        if(i % 2 == 0) two = dp[i/2];
        three = dp[i-1];
        dp[i] = min(min(one, two) , three) + 1;
    }

    return dp[n];
}