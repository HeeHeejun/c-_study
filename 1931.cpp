#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> meetingTime;

void maxMeeting()
{
    pair<int, int> current = meetingTime.top();
    meetingTime.pop();
    int result = 1;
    while(!meetingTime.empty())
    {
        int start = meetingTime.top().second;
        int end = meetingTime.top().first;
        meetingTime.pop();

        if(current.first <= start)
        {
            current = {end, start};
            result++;
        }
    }
    cout << result;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        pair<int, int> tmp;
        cin >> tmp.second >> tmp.first;
        meetingTime.push(tmp);
    }

    maxMeeting();
}