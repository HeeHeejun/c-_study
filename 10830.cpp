#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[5][5];
int tmp[5][5];
int n;

void matrixMultipe(int (&a)[][5])
{
    int num = 0;
    int copy[5][5];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            copy[i][j] = a[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int t = 0; t < n; t++)
            {
                num += copy[t][j] * copy[i][t];
            }
            tmp[i][j] = num % 1000;
            num = 0;
        }
    }
}

void matrixMultipe(int (&a)[][5], int (&b)[][5])
{
    int num = 0;
    int copy1[5][5];
    int copy2[5][5];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            copy1[i][j] = a[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            copy2[i][j] = b[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int t = 0; t < n; t++)
            {
                num += copy1[i][t] * copy2[t][j];
            }
            tmp[i][j] = num % 1000;
            num = 0;
        }
    }
}

void multiple(long long m)
{
    if(m == 1)
    {
        return;
    }
    multiple(m/2);
    if(m % 2 == 0)
    {
        matrixMultipe(tmp);
    }
    else
    {
        matrixMultipe(tmp);
        matrixMultipe(tmp, matrix);
    }
}

int main()
{
    long long m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            tmp[i][j] = matrix[i][j] % 1000;
        }
    }

    multiple(m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << tmp[i][j] << " ";
        }
        cout << "\n";
    }
}