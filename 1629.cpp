//(실1) 곱셈
//a,b,c가 주어질때, a의 b승을 c로 나눈 나머지를 출력
//분할정복

#include <iostream>

using namespace std;

long long pow(int num, int exponent, int rest);

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    long long result = pow(a, b, c);
    cout << result;
}

long long pow(int num, int exponent, int rest)
{
    if(exponent == 1){ return num % rest; }

    long long temp = pow(num, exponent/2, rest) % rest;
    long long even = (temp*temp) % rest;
    if(exponent % 2 == 0) return even;
    else return (even * num) % rest;
}