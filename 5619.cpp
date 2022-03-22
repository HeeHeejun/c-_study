#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
int main()
{
    int n; // n은 개수
    int temp, first, last; // a는 숫자
    vector<int> small;
    priority_queue<int, vector<int>, greater<int>> num, min; 
    string result;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        num.push(temp);
    }
    
    if(n < 5)
    {
        for(int i = 0; i < n; i++)
        {
            small.push_back(num.top());
            num.pop();
        }
    }
    else
    {
        for(int i = 0; i < 5; i++)
        {
            small.push_back(num.top());
            num.pop();
        }
    }

    for(int i = 0; i < small.size() - 1; i++)
    {
        first = small[i];
        for(int j = 0; j < small.size() - 1; j++)
        {
            if(i == j)
            {
                continue;
            }
            last = small[j];
            cout << to_string(first) + to_string(last) <<"\n";
            min.push(stoi(to_string(first) + to_string(last)));
        }
    }

    min.pop();
    min.pop();

    cout << min.top();
    return 0;
}