#include <iostream>
#include <queue>

using namespace std;

void push(queue<int>& q, int x);
int pop(queue<int>& q);
int size(queue<int>& q);
int empty(queue<int>& q);
int front(queue<int>& q);
int back(queue<int>& q);

int main()
{
    queue<int> que;
    int command_n, n;
    string command;

    cin >> command_n;
    for(int i = 0; i < command_n; i++)
    {
        cin >> command;
        if(command == "push")
        {
            cin >> n;
            push(que, n);
        }
        else if(command == "pop")
        {
            cout << pop(que) << "\n";
        }
        else if(command == "size")
        {
            cout << size(que) << "\n";
        }
        else if(command == "empty")
        {
            cout << empty(que) << "\n";
        }
        else if(command == "front")
        {
            cout << front(que) << "\n";
        }
        else if(command == "back")
        {
            cout << back(que) << "\n";
        }
    }
    return 0;
}

void push(queue<int>& q, int x)
{
    q.push(x);
    return;
}

int pop(queue<int>& q)
{
    if(q.empty())
    {
        return -1;
    }
    
    int temp = q.front();
    q.pop();
    return temp;
}

int size(queue<int>& q)
{
    return q.size();
}

int empty(queue<int>& q)
{
    if(q.empty())
    {
        return 1;
    }
    return 0;
}

int front(queue<int>& q)
{
    if(q.empty())
    {
        return -1;
    }
    return q.front();
}

int back(queue<int>& q)
{
    if(q.empty())
    {
        return -1;
    }
    return q.back();
}