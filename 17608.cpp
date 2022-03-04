#include <iostream>
#include <stack>
/*
막대기의 개수와 막대기들의 길이를 입력받고 뒤에서 봤을 때
보이는 막대의 개수를 구함
*/
using namespace std;
int main()
{
    stack<int> high;
    int n;
    int most;
    int count = 1;
    int temp;

    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        high.push(temp);
    }
    
    most = high.top();
    high.pop();

    for(int i = 0; i < n - 1; i++)
    {
        if(high.top() > most)
        {
            most = high.top();
            count++;
        }
        high.pop();
    }

    cout << count;
    
    return 0;
}