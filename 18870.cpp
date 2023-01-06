//(실2) 좌표 압축
//자신보다 작은 좌표의 개수를 각각 출력
//정렬

#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int result[n];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push({temp,i});
    }

    int order = 0;
    pair<int,int> current = pq.top();
    pq.pop();

    result[current.second] = order;
    while(!pq.empty())
    {
        pair<int,int> next = pq.top();
        pq.pop();
        if(current.first != next.first) order++;

        result[next.second] = order;
        current = next;
    }

    for(auto item : result)
    {
        cout << item << " ";
    }
}