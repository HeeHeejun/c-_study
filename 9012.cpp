#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
    int t;
    string str;
    bool notPrint;

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> str;
        notPrint = true;
        stack<char> stk;

        for(int j = 0; j < str.size(); j++)
        {
            if(str[j] == '(')
            {
                stk.push(str[i]);
            }
            else if(str[j] == ')')
            {
                if(stk.empty())
                {
                    cout << "NO" << "\n";
                    notPrint = false;
                    break;
                }
                stk.pop();
            }
        }
        
        if( notPrint && !stk.empty())
        {
            cout << "NO" << "\n";
        }
        else if( notPrint && stk.empty())
        {
            cout << "YES" << "\n";
        }
    }

    return 0;
}