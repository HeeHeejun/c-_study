//(실3)2xn 타일링
// 2xn의 공간에 2x1, 1x2의 타일의 넣는 방법의 수를 출력
// dp 이용

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