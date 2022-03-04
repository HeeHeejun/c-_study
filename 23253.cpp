#include <iostream>

using namespace std;
int main()
{
    int n, m, k;
    int n_temp;
    int max;

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> k >> n_temp;
        max = n_temp;
        for(int j = 0; j < k - 1; j++)
        {
            cin >> n_temp;
            if(max < n_temp)
            {
                cout << "No";
                return 0;
            }
            max = n_temp;
        }
    }
    cout << "Yes";
    return 0;
}