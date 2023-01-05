#include <iostream>

using namespace std;
int main()
{
    int n, fiveCount = 0;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        if (i % 5 == 0) fiveCount++;
        if (i % 25 == 0) fiveCount++;
        if (i % 125 == 0) fiveCount++;
    }

    cout << fiveCount;
}