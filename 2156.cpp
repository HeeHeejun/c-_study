//(��1) ������ �ý�
//�������� 3�� ������ �� ���� �������� �ִ� ���� ����϶�
//DP

#include <iostream>
#include <algorithm>
using namespace std;
int quantity[10001] = {0};
int maxDrink[10001] = {0};
int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> quantity[i];
    }
    maxDrink[1] = quantity[1];
    maxDrink[2] = quantity[1] + quantity[2];
    for(int i = 3; i <= n; i++)
    {
        maxDrink[i] = max({maxDrink[i-1], maxDrink[i-2] + quantity[i], maxDrink[i-3] + quantity[i-1] + quantity[i]}); 
    }

    cout << maxDrink[n];
}
