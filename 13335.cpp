#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int n, w, l; // n = 트럭수, w = 다리길이, l = 다리최대하중
    int vehicle = 0;
    int  time = 0, plus_w = 0, plus_n = 0; 
    queue<int> bridge, wait;
    cin >> n >> w >> l;

    for(int i = 0; i < n; i++)
    {
        cin >> vehicle;
        wait.push(vehicle);
    }
        
    do
    {
        if(bridge.size() == w)
        {
            vehicle = bridge.front();
            bridge.pop();
            plus_w -= vehicle;
            if(vehicle != 0) {plus_n -= 1;}
        }
        
        vehicle = wait.front();
        if(vehicle + plus_w <= l && plus_n <= w && !wait.empty())
        {
            wait.pop();

            bridge.push(vehicle);
            plus_w += vehicle;
            plus_n += 1;
        }
        else 
        {
            bridge.push(0);
        }
         time++;
    }while(plus_n != 0 || !wait.empty());

    cout << time;
    return 0;
}