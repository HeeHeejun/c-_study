#include <iostream>
#include <queue>

using namespace std;

struct print
{
    int impt;
    int order;
};

int main()
{
    queue<print> q;
    int test, n, m, pop_n;
    print important , temp;
    bool isBig = true;

    cin >> test;
    for(int i = 0; i < test; i++)
    {
        pop_n = 0;
        cin >> n >> m;
        for(int j = 0; j < n; j++)
        {
            cin >> important.impt;
            important.order = j;
            q.push(important);
        }
        
        while (!q.empty())
        {
            isBig = true;
            temp = q.front();
            q.pop();
            int size = q.size();
            for(int j = 0; j < q.size(); j++)
            {
                if(temp.impt < q.front().impt)
                {
                    isBig = false;
                }
                q.push(q.front());
                q.pop();
            }

            if(isBig == true)
            {
                pop_n++;
                if(temp.order == m)
                {
                    cout << pop_n << "\n";
                    break;
                }
            }
            else
            {
                q.push(temp);
            }
        }

        while(!q.empty()){q.pop();}
    }
    return 0;
}