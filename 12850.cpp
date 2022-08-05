#include <iostream>

using namespace std;
long long matrix[9][9] = {0};
long long tmp[9][9] = {0};

void multiple(long long (&a)[][9], long long (&b)[][9])
{
    long long copy1[9][9];
    long long copy2[9][9];
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            copy1[i][j] = a[i][j];
            copy2[i][j] = b[i][j];
        }
    }

    for(int i = 1; i < 9; i++)
    {
        for(int j = 1; j < 9; j++)
        {
            long long result = 0;
            for(int k = 1; k < 9; k++)
            {
                result += copy1[i][k] * copy2[k][j];
            }
            // cout << result << "\n";
            tmp[i][j] = result % 1000000007;
        }
    }
}

void powerOfN(int n)
{
    if(n == 1)
    {
        return;
    }
    
    powerOfN(n/2);
    if (n % 2 == 0)
    {
        multiple(tmp, tmp);
    }
    else
    {
        multiple(tmp, tmp);
        multiple(tmp, matrix);
    }
}

int main()
{
    //1은 정보과학관, 2는 전산관, 3은 미래관
    //4는 산양관, 5는 한경직기념관, 6은 진리관
    //7은 학생회관, 8은 형남공학관
    matrix[1][2] = 1; matrix[2][1] = 1;
    matrix[1][3] = 1; matrix[3][1] = 1;
    matrix[2][3] = 1; matrix[3][2] = 1;
    matrix[2][4] = 1; matrix[4][2] = 1;
    matrix[3][4] = 1; matrix[4][3] = 1;
    matrix[3][5] = 1; matrix[5][3] = 1;
    matrix[4][5] = 1; matrix[5][4] = 1;
    matrix[4][6] = 1; matrix[6][4] = 1;
    matrix[5][6] = 1; matrix[6][5] = 1;
    matrix[5][8] = 1; matrix[8][5] = 1;
    matrix[6][7] = 1; matrix[7][6] = 1;
    matrix[7][8] = 1; matrix[8][7] = 1;

    tmp[1][2] = 1; tmp[2][1] = 1;
    tmp[1][3] = 1; tmp[3][1] = 1;
    tmp[2][3] = 1; tmp[3][2] = 1;
    tmp[2][4] = 1; tmp[4][2] = 1;
    tmp[3][4] = 1; tmp[4][3] = 1;
    tmp[3][5] = 1; tmp[5][3] = 1;
    tmp[4][5] = 1; tmp[5][4] = 1;
    tmp[4][6] = 1; tmp[6][4] = 1;
    tmp[5][6] = 1; tmp[6][5] = 1;
    tmp[5][8] = 1; tmp[8][5] = 1;
    tmp[6][7] = 1; tmp[7][6] = 1;
    tmp[7][8] = 1; tmp[8][7] = 1;

    int num; 
    cin >> num;

    powerOfN(num);
    cout << tmp[1][1];
}