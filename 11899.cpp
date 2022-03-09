#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main()
{
    stack<int> stk;
    string str;

    cin >> str;
    
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(')
        {
            stk.push(str[i]);
        }
        else
        {
            if(!stk.empty() && stk.top() == '(')
            {
                stk.pop();
            }
            else
            {
                stk.push(str[i]);
            }
        }
    }
    
    cout << stk.size();
    return 0;
}