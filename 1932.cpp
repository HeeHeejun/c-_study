//(실1) 정수 삼각형
// 대각선 양옆만 내려갈 경우, 내려가는 곳의 합이 가장 최대인 값을 구해라
//dp

#include <iostream>
#include <vector>

using namespace std;
vector<int> result;
int max(int n);
int main()
{
    int n;
    cin >> n;
    cout << max(n);
}

int max(int n)
{
    result.resize(n,0);
    for(int i = 0; i < n; i++)
    {
        vector<int> current;
        for(int j = 0; j <= i; j++)
        {
            int temp;
            cin >> temp;
            current.push_back(temp);


            if(j == 0) current[j] += result[j];
            else
            {
                current[j] += max(result[j-1], result[j]);
            }
        }

        for(int j = 0; j <= i; j++)
        {
            result[j] = current[j];
        }
    }
    
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(max < result[i]) max = result[i];
    }
    
    return max;
}