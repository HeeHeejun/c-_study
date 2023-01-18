//(��2) ���� �� �����ϴ� �κ� ����
// ������ �־����� �� ���� �� �����ϴ� �κ� ������ ���̸� ���
// ���� Ž��

#include <iostream>
#define MAX 1000000
using namespace std;
int LIS[MAX] = {};
void findLIS(int n);
int main()
{
    int n; cin >> n;
    findLIS(n);
}

void findLIS(int n)
{
    int first, size = 1; cin >> first;
    LIS[0] = first;

    for(int i = 1; i < n; i++)
    {
        int temp; cin >> temp;
        auto it = lower_bound(LIS, LIS + size, temp);
        if(*it == 0) size++;
        *it = temp;
    }

    cout <<size;
}