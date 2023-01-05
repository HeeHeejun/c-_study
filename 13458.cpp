#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int room, main, sub;
    cin >> room;
    int people[room];
    long long result = 0;

    for(int i = 0; i < room; i++)
    {
        cin >> people[i];
    }
    cin >> main >> sub;

    for(int i = 0; i < room; i++)
    {
        if (people[i] < main)
        {
            result += 1;
        }
        else
        {
            result += ceil(((double)people[i] - main)/ sub) + 1;
        }
    }
    cout << result;
}
