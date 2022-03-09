#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
    stack<int> stk;
    int n, now, i = 1, pop_n = 0;
    string push_pop = "";
    cin >> n;
    cin >> now;

    do
    {
        if(now >= i)
        {
            stk.push(i);
            push_pop += "+";
            i++;
        }
        if(now == stk.top())
        {
            stk.pop();
            push_pop += "-";
            pop_n++;
            if(pop_n != n)
                cin >> now;
        }
        else if(now < stk.top())
        {
            cout << "NO";
            return 0;
        }
    }while(!(pop_n == n));

    for(int j = 0; j < push_pop.size(); j++)
    {
        cout << push_pop[j] << "\n";
    }
    
    return 0;
}