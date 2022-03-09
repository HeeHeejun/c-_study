#include <iostream>
#include <stack>
#include <string>

using namespace std;

void push(stack<int>& stk_c, int x);
int pop(stack<int>& stk_c);
int size(stack<int>& stk_c);
int empty(stack<int>& stk_c);
int top(stack<int>& stk_c);

int main()
{
    int n, push_n;
    stack<int> stk;
    string command;

    cin >> n;
    for(int i; i < n; i++)
    {
        cin >> command;
        if(command == "push")
        {
            cin >> push_n;
            push(stk, push_n);
        }
        else if(command == "pop")
        {
            cout << pop(stk) << "\n";
        }
        else if(command == "size")
        {
            cout << size(stk) << "\n";
        }
        else if(command == "empty")
        {
            cout << empty(stk) << "\n";
        }
        else if(command == "top")
        {
            cout << top(stk) << "\n";
        }
    }
    return 0;
}

void push(stack<int>& stk_c, int x)
{
    stk_c.push(x);
}

int pop(stack<int>& stk_c)
{
    int result;
    if(stk_c.empty())
    {
        return -1;
    }
    result = stk_c.top();
    stk_c.pop();

    return result;
}

int size(stack<int>& stk_c)
{
    return stk_c.size();
}

int empty(stack<int>& stk_c)
{
    if(stk_c.empty())
    {
        return 1;
    }
    return 0;
}

int top(stack<int>& stk_c)
{
    if(stk_c.empty())
    {
        return -1;
    }
    return stk_c.top();
}
