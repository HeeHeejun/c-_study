//(��3)2xn Ÿ�ϸ�
// 2xn�� ������ 2x1, 1x2�� Ÿ���� �ִ� ����� ���� ���
// dp �̿�

#include <iostream>
using namespace std;

int rest[1001] = {0};
int main()
{
    int n;
    cin >> n;
    rest[1] = 1; rest[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        rest[i] = (rest[i-1] + rest[i-2]) % 10007;
    }

    cout << rest[n];
}