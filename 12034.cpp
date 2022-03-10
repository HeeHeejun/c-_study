#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int t, p, p_thing, temp, size;
    queue<int> price;

    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cin >> p;
        for(int j = 0; j < 2*p; j++)
        {
            cin >> p_thing;
            price.push(p_thing);
        }
        
        cout << "Case #" << i << ":";

        while(!price.empty())
        {
            p_thing = price.front();
            price.pop();

            if(p_thing / 0.75 == price.front())
            {
                price.pop();
                cout << " " << p_thing;
            }
            else
            {
               size = price.size();
               for(int j = 0; j < size; j++)
               {
                    if(p_thing / 0.75 == price.front())
                    {
                        price.pop();
                        cout << " " << p_thing;
                        for(int a = 0; a < size - j - 1; a++)
                        {
                            temp = price.front();
                            price.pop();
                            price.push(temp);
                        }
                        break;
                    }
                    else 
                    {
                        temp = price.front();
                        price.pop();
                        price.push(temp);
                    }
               }
            }
        }
        cout << "\n";
    }
}