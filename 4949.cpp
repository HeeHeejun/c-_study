#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
    string str;
    stack<char> stk;
    bool play = true;
    bool notPrint;

    while(play)
    {
        getline(cin, str);
        notPrint = true;

        if(str == ".")
        {
            play = false;
            return 0;
        }

        for(int i = 0; str[i] != '.'; i++)
        {
            if(str[i] == '(' || str[i] == '[')
            {
                stk.push(str[i]);
            }
            else if(str[i] == ')')
            {
                if( stk.empty() || stk.top() != '(')
                {
                    cout << "no" << endl;
                    notPrint = false;
                    while(!stk.empty()){ stk.pop(); }
                    break;
                }
                stk.pop();
            }
            else if(str[i] == ']')
            {
                if(stk.empty() || stk.top() != '[')
                {
                    cout << "no" << endl;
                    notPrint = false;
                    while(!stk.empty()){ stk.pop(); }
                    break;
                }
                stk.pop();
            }
            else
            {
                continue;
            }
        }

        if( notPrint && (!stk.empty()) )
        {
            cout << "no" << endl;
            while(!stk.empty()){ stk.pop(); }
        }
        else if ( notPrint && stk.empty() )
        {
            cout << "yes" << endl;
        }


    }
    return 0;
}