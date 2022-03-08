#include <iostream>
#include <stack>
#include <string>

using namespace std;

int smallBracket(stack<int>& cal_clone, string& ex);
int bigBracket(stack<int>& cal_clone, string& ex);

int myindex = 0;

int main()
{
    string example;
    stack<int> calculate;
    int answer = 0;
    int temp;
    cin >> example; 

    while(myindex <= example.size() - 1)
    {
        switch(example[myindex])
        {
            case '(':
                myindex++;
                temp = smallBracket(calculate, example);
                calculate.push(temp);
                cout << "temp: " << temp << endl;
                break;
            case '[':
                myindex++;
                temp = bigBracket(calculate, example);
                calculate.push(temp);
                cout << "case [ play" << endl;
                break;
            default:
                cout << 0;
                return 0;
                break;
        }
    }

    while(!(calculate.empty()))
    {
        answer += calculate.top();
        cout << "cal not empty" << endl;
        calculate.pop();
    }

    cout << answer;
    return 0;
}

int smallBracket(stack<int>& cal_clone, string& ex)
{
    int result;

    if(ex[myindex] == '(')
    {
        result = 2*smallBracket(cal_clone, ex);
    }
    else if(ex[myindex] == ')')
    {
        result = 2;
    }
    else if(ex[myindex] == '[')
    {
        result = 2*bigBracket(cal_clone, ex);
    }
    else
    {
        return 0;
    }
    cout << "result price:" << result << endl;
    myindex++;
    return result;
}

int bigBracket(stack<int>& cal_clone, string& ex)
{
    cout << "big play" << endl;
    myindex++;
    int result;

    if(ex[myindex] == '(')
    {
        result = 3*smallBracket(cal_clone, ex);
    }
    else if(ex[myindex] == ']')
    {
        result = 3;
        if(ex[myindex + 1] == '(')
        {
            myindex++;
            result += smallBracket(cal_clone, ex);
        }
        else if(ex[myindex + 1] == '[')
        {
            myindex++;
            result += bigBracket(cal_clone, ex);
        }
    }
    else if(ex[myindex] == '[')
    {
        result = 3*bigBracket(cal_clone, ex);
    }
    else
    {
        return 0;
    }
    cout << "result price:" << result << endl;
    myindex++;
    return result;
}