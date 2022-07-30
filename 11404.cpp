#include <iostream>
#define INF 123456789
using namespace std;

int minCost[101][101];

void floydWarshall(int vertix, int edge)
{
    for(int i = 1; i <= vertix; i++)
    {
        for(int j = 1; j <= vertix; j++)
        {
            if(i == j) { minCost[i][j] = 0; }
            else{ minCost[i][j] = INF; }
        }
    }
    
    for(int i = 0; i < edge; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        if(minCost[from][to] > cost) minCost[from][to] = cost;
    }

    
    for(int i = 1; i <= vertix; i++)
    {
        for(int j = 1; j <= vertix; j++)
        {
            for(int t = 1; t <= vertix; t++)
            {
                if(minCost[j][t] > minCost[j][i] + minCost[i][t])
                {
                    minCost[j][t] = minCost[j][i] + minCost[i][t];
                }
            }
        }
    }

    for(int i = 1; i <= vertix; i++)
    {
        for(int j = 1; j <= vertix; j++)
        {
            if(minCost[i][j] == INF) { cout << 0 << " "; }
            else{ cout << minCost[i][j] << " "; }
        }
        cout << "\n";
    }
}

int main()
{
    int vertix, edge;
    cin >> vertix >> edge;

    floydWarshall(vertix, edge);
}