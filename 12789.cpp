#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main()
{
    stack<int> wait;
    int n, front;
    int next = 1;

    cin >> n;

    for( int i = 0 ; i < n ; i++ )
    {
        cin >> front;
        
        if(front == next)
        {
            next++;     
        }
        else if(!wait.empty() && wait.top() == next)
        {
            while(next != wait.top())
            {
                wait.pop();
                next++;
            }
        }
        else
        {
            if(wait.empty() || wait.top() > front)
            {
                wait.push(front);
            }
            else 
            {
                cout << "Sad";
                return 0;
            }
        }
    }
    cout << "Nice";
    return 0;
}