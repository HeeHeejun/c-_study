#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    int n, m, p, l, temp; //n은 과목수, m은 마일리지, p는 신청한 사람 수, l은 과목의 수강인원 수
    int num = 0;
    priority_queue<int, vector<int>, less<int>> mileage;
    priority_queue<int, vector<int>, greater<int>> possible;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> p >> l;
        for(int j = 0; j < p; j++)
        {
            cin >> temp;
            mileage.push(temp);
        }

        if(p < l)
        {
            possible.push(1);
        }
        else
        {
            for(int j = 0; j < l - 1; j++)
            {
                mileage.pop();
            }
            possible.push(mileage.top());
        }
        mileage = priority_queue<int, vector<int>, less<int>>();
    }
    
    while(!possible.empty())
    {
        m -= possible.top();
        num++;
        if(m < 0)
        {
            num--;
            break;
        }
        possible.pop();
    }

    cout << num;
    return 0;
}