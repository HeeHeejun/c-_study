#include <iostream>
#include <stack>
#include <string>

using namespace std;

int Bracket(stack<char>& cal_clone, string& ex);

int myIndex = 0;
bool correct = true;

int main()
{
    string example;
    stack<char> calculate;
    int answer = 0;
    cin >> example; 
    
    while(myIndex <= example.size())
    {   
        if(correct == false)
        {
            cout << 0;
            return 0;
        }
        else
        {
            answer += Bracket(calculate, example);
        }
    }
    if(correct == false || !calculate.empty())
    {
        cout << 0;
        return 0;
    }
    cout << answer;
    return 0;
}

int Bracket(stack<char>& cal_clone, string& ex)
{
    int temp = 1;
    int result = 0;
    do
    {    
        switch (ex[myIndex])
        {
        case '(':
            if(myIndex == ex.size() - 1)
            {
                correct = false;
                return 0;
            }
            cal_clone.push(ex[myIndex]);
            temp *= 2;
            break;
        case '[':
            if(myIndex == ex.size() - 1)
            {
                correct = false;
                return 0;
            }
            cal_clone.push(ex[myIndex]);
            temp *= 3;
            break;
        case ')':
            if(cal_clone.empty() || cal_clone.top() != '(')
            {
                correct = false;
                return 0;
            }
            else if(ex[myIndex -1] == '(')
            {
                result += temp;
            }
            temp /= 2;
            cal_clone.pop();
            break;
        case ']':
            if(cal_clone.empty() || cal_clone.top() != '[')
            {
                correct = false;
                return 0;
            }
            else if(ex[myIndex - 1] == '[')
            {
                result += temp;
            }
            temp /= 3;
            cal_clone.pop();
            break;
        }
        myIndex++;
    }while (!cal_clone.empty());
    return result;
}