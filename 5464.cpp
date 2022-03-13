#include <iostream>
#include <queue>

using namespace std;

struct parking_p
{
    int pay;
    int car_n = 0;
    int car_w;
};

int main()
{
    int n, m ,order, result = 0; //n는 주차공간의 수, m은 차량의수
    parking_p *R = nullptr; //R는 주차공간에 대한 단위 무게당 요금
    int *W = nullptr; //W는 차량의 무게
    bool ispark = false;
    queue<int> wait;

    cin >> n >> m;
    R = new parking_p[n];
    W = new int[m];


    for(int i = 0; i < n; i++)
    {
        cin >> R[i].pay;
    }

    for(int i = 0; i < m; i++)
    {
        cin >> W[i];
    }

    for(int i = 0; i < 2*m; i++)
    {
        cin >> order;
        //주차공간 찾기
        if(order > 0)
        {
            for(int j = 0; j < n; j++)
            {
                if(R[j].car_n == 0)
                {
                    R[j].car_w = W[order - 1];
                    R[j].car_n = order;
                    ispark = true;
                    break;
                }
            }
            if(ispark == false)
            {
                wait.push(order);
            }
            ispark = false;
        }
        else 
        {
            for(int j = 0; j < n; j++)
            {
                if(R[j].car_n == -1*(order))
                {
                    result += R[j].pay *R[j].car_w;
                    R[j].car_n = 0;

                    if(!wait.empty())
                    {
                        order = wait.front();
                        wait.pop();
                        R[j].car_n = order;
                        R[j].car_w = W[order - 1];
                    }
                    break;
                }
            }
        }
    }
    cout << result;
    delete [] R, W;

    return 0;
}