//방향이 정해진 매트릭스에서 
//어느 방향으로 이동해도 safeZone으로 가는
//최소의 safeZone의 수를 구하기

//union_find 알고리즘
//dfs 알고리즘 >> 왜 dfs를 사용해야하지? 서로 다른 사이클의 수만 알면 되는 것인데

#include <iostream>
#include <vector>
#include <set>

using namespace std;
pair<int, int> parent[1001][1001];
char matrix[1001][1001];

pair<int, int> getParent(pair<int, int> index)
{
    if(parent[index.first][index.second] == index)
    {
        return index;
    }
    else
    {
        return parent[index.first][index.second] = getParent(parent[index.first][index.second]);
    }
}

void unionParent(pair<int, int> a, pair<int, int> b)
{
    a = getParent(a);
    b = getParent(b);

    if(a > b) parent[a.first][a.second] = parent[b.first][b.second];
    else parent[b.first][b.second] = parent[a.first][a.second];
}

bool findParent(pair<int, int> a, pair<int, int> b)
{
    a = getParent(a);
    b = getParent(b);

    if(a == b) return true;
    else return false;
}

void countSafeZone(int column, int row)
{
    for(int i = 1; i <= column; i++)
    {
        for(int j = 1; j <= row; j++)
        {
            if(matrix[i][j] == 'D')
            {
                unionParent({i, j}, {i+1, j});
            }
            else if(matrix[i][j] == 'U')
            {
                unionParent({i, j}, {i-1, j});
            }
            else if(matrix[i][j] == 'L')
            {
                unionParent({i, j}, {i, j-1});
            }
            else if(matrix[i][j] == 'R')
            {
                unionParent({i, j}, {i, j+1});
            }
        }
    }

    set<pair<int, int>> s;
    for(int i = 1; i <= column; i++)
    {
        for(int j = 1; j <= row; j++)
        {
            s.insert(getParent({i,j}));
        }
    }

    cout << s.size();
}

int main()
{
    int column, row;
    cin >> column >> row;

    for(int i = 1; i <= column; i++)
    {
        for(int j = 1; j <= row; j++)
        {
            cin >> matrix[i][j];
            parent[i][j] = {i, j};
        }
    }
    
    countSafeZone(column, row);
}