//(��5) LCS 
//�� ���ڿ��� �־����� �� ���� ���� �κ� ������ ���
//dp

#include <iostream>

using namespace std;
string experiment;
string control;
int LCS[1001][1001] = {};
void findLcs();
int main()
{
    cin >> experiment >> control;
    findLcs();
}  

void findLcs()
{
    for(int i = 1; i <= experiment.size(); i++)
    {
        for(int j = 1; j <= control.size(); j++)
        {
            if(experiment[i-1] == control[j-1])
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else
            {
                LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]); 
            }
        }
    }

    cout << LCS[experiment.size()][control.size()];
}