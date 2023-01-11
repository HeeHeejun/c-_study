//(골2) 후위 표기식
// 중위표기식을 후위표기식으로 변경
// stack

#include <iostream>
#include <stack>

using namespace std;
int main()
{
    string expression;
    cin >> expression;

    stack<char> s;

    for(int i = 0; i < expression.size(); i++)
    {
        if(expression[i] >= 'A' && expression[i] <= 'Z')
        {
            cout << expression[i];
        }
        else if(expression[i] == '(')
        {
            s.push('(');
        }
        else if(expression[i] == ')')
        {
            char temp = s.top();
            s.pop();
            while(temp != '(')
            {
                cout << temp;
                temp = s.top();
                s.pop();
            }
        }
        else
        {
            if(s.empty()) 
            {
                s.push(expression[i]);
                continue;
            }

            if(expression[i] == '+' || expression[i] == '-')
            {
                char temp = s.top();
                s.pop();
                while(!s.empty() && temp != '(')
                {
                    cout << temp;
                    temp = s.top();
                    s.pop();
                }
                if(temp == '(') s.push(temp);
                else cout << temp;
            }
            else
            {
                char temp = s.top();
                if(temp == '*' || temp == '/')
                {
                    s.pop();
                    cout << temp;
                }
            }
            s.push(expression[i]);
        }
    }

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}


