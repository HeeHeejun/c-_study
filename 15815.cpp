#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
    stack<int> calculate;
    string formula;
    int temp;

    cin >> formula;

    for(int i = 0; i < formula.size(); i++)
    {
        if(formula[i] >= '0' && formula[i] <= '9')
        {
            calculate.push( formula[i] - '0');
        }
        else if(formula[i] == '+')
        {
            temp = calculate.top();
            calculate.pop();
            temp = calculate.top() + temp;
            calculate.pop();
            calculate.push(temp);
        }
        else if(formula[i] == '-')
        {
            temp = calculate.top();
            calculate.pop();
            temp = calculate.top() - temp;
            calculate.pop();
            calculate.push(temp);
        }
        else if(formula[i] == '*')
        {
            temp = calculate.top();
            calculate.pop();
            temp = calculate.top() * temp;
            calculate.pop();
            calculate.push(temp);  
        }
        else if(formula[i] == '/')
        {
            temp = calculate.top();
            calculate.pop();
            temp = calculate.top() / temp;
            calculate.pop();
            calculate.push(temp);    
        }
    }

    cout << calculate.top();
    return 0;
}