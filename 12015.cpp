//(골2) 가장 긴 증가하는 부분 수열
// 수열이 주어졌을 때 가장 긴 증가하는 부분 수열의 길이를 출력
// 이진 탐색

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