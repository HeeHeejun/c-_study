// (��3) 1, 2, 3 ���ϱ�
// �־��� ���ڸ� 1,2,3�� ������ ��Ÿ���� ����� ���� ���
// dp �̿�

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