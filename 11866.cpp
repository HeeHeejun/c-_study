#include <iostream>
#include <queue>

using namespace std;
int main()
{
    queue<int> circle;
    int n, k, temp;
    int k_count = 1;
    
    cin >> n>> k;

    for(int i = 1; i <= n; i++)
    {
        circle.push(i);
    }

    cout << "<";
    while(!circle.empty())
    {
        if(k_count < k)
        {
            k_count++;
            temp = circle.front();
            circle.pop();
            circle.push(temp);
        }
        else
        {
            k_count = 1;
            temp = circle.front();
            circle.pop();
            if(!circle.empty())
            {
                cout << temp << ", ";
            }
            else
            {
                cout << temp << ">";
            }
        }
    }

    return 0;
}