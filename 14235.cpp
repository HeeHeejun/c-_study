#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    int n, a; // n은 방문한 횟수, a는 선물 충전 개수(0일때는 아이들을 만난 것)
    priority_queue<int, vector<int>> gift;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(a == 0)
        {
            if (gift.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << gift.top() << "\n";
                gift.pop();
            }
        }
        else
        {
            int gift_n = a;
            for(int j = 0; j < gift_n; j++)
            {
                cin >> a;
                gift.push(a);
            }
        }
    }

    return 0;
}