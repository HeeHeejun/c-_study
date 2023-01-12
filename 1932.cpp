//(��1) ���� �ﰢ��
// �밢�� �翷�� ������ ���, �������� ���� ���� ���� �ִ��� ���� ���ض�
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