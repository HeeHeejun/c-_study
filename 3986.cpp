#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
    int n;
    int result = 0;
    string temp;
    stack<char> str;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < temp.size(); j++)
        {
            if (!str.empty() && str.top() == temp[j])
            {
                str.pop();
                continue;
            }
            str.push(temp[j]);
        }

        if (str.empty())
        {
            result++;
        }
        else
        {
            while (!str.empty())
            {
                str.pop();
            }
        }
    }

    cout << result;
    return 0;
}