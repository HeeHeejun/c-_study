#include <iostream>
#include <stack>

using namespace std;
int main()
{
    int k ,n , result = 0;
    stack<int> plus;

    cin >> k;
    
    for(int i = 0; i < k; i++)
    {
        cin >> n;

        if(n == 0)
        {
            if(!plus.empty())
            {
                plus.pop();
            }
        }
        else
        {
            plus.push(n);
        }
    }

    while(!plus.empty())
    {
        result += plus.top();
        plus.pop();
    }

    cout << result;
    return 0;
}