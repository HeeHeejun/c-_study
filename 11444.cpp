//(골2) 피보나치 수 6
// 피보나치 수를 1,000,000,007로 나눈 나머지를 출력(n <= 1,000,000,000,000,000,000)
// 분할 정복, 행렬을 이용한 피보나치 
// [ F(n+1), F(n)  ] = [1,1] ^ n
// [ F(n)  , F(n-1)] = [1,0]

#include <iostream>
#define divider 1000000007LL
using namespace std;

void multipleTemp(long long n);
void multipleMatrix(long long a[][2], long long b[][2]);
void pibonacci(long long n);
long long odd[2][2] = {{1,1}, {1,0}};
long long temp[2][2] = {{1,1}, {1,0}};
int main()
{
    long long n; cin >> n;
    pibonacci(n);
    cout << temp[0][1];
}

void multipleMatrix(long long a[][2], long long b[][2])
{
    long long first = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % divider;
    long long second = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % divider;
    long long third = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % divider;
    long long fourth = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % divider;

    a[0][0] = first % divider;
    a[0][1] = second % divider;
    a[1][0] = third % divider;
    a[1][1] = fourth % divider;   
}

void multipleTemp(long long n)
{
    if(n % 2 == 0)
    {
        multipleMatrix(temp, temp);
    }
    else
    {
        multipleMatrix(temp, temp);
        multipleMatrix(temp, odd);
    }
}

void pibonacci(long long n)
{
    if(n==1) return;

    pibonacci(n/2);

    multipleTemp(n);
}
