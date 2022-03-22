#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;
int main()
{
    pair<int, char> num;
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

    int n, command;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> command;
        if(command != 0)
        {
            if(command < 0)
            {
                num.first = abs(command);
                num.second = '-';
                pq.push(num);
            }
            else
            {
                num.first = command;
                num.second = 'P';
                pq.push(num);
            }
        }
        else
        {
            if(!pq.empty())
            {
                num = pq.top();
                if(num.second == '-') {cout << num.second << num.first << '\n';}
                else {cout << num.first << '\n';}
                pq.pop();
            }
            else {cout << 0 << "\n";}
        }
    }

    return 0;
}