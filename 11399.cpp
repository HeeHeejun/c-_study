//(실4) ATM
//모든 사람이 각각 돈을 인출하는데 걸리는 시간의 합이 최소가 될 때, 최소값 출력
//정렬

#include <iostream>
#include <queue>

using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    int sum = 0, timePerPerson = 0;
    for(int i = 0; i < n; i++)
    {
        timePerPerson += pq.top();
        pq.pop();
        sum += timePerPerson;
    }

    cout << sum;
}