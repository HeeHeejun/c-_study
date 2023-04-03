//(��1) 1�� ����� 
// X�� 3���� ������ �������� 3���� ������, x�� 2�� ���������� 2�� ������, -1�� �Ѵ�. �־��� ���� ���� 1�� ����� �ּ��� Ƚ���� ���
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