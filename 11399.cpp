//(��4) ATM
//��� ����� ���� ���� �����ϴµ� �ɸ��� �ð��� ���� �ּҰ� �� ��, �ּҰ� ���
//����

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