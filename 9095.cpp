// (실3) 1, 2, 3 더하기
// 주어진 숫자를 1,2,3의 합으로 나타내는 방법의 수를 출력
// dp 이용

#include <iostream>
int dp[11] = {};
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 0; i < testCase; i++)
    {
        int n;
        cin >> n;
        if(dp[n] == 0)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dp[j] == 0) dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
            }
            
        }
        cout << dp[n] << "\n";
    }

}