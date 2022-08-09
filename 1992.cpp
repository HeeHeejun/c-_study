//분할 정복을 이용한 흑백을 압축해서 표현

#include <iostream>
using namespace std;

char matrix[65][65];
string quadTree(int n, int x, int y)
{
    if(n == 1)
    {
        if(matrix[x][y] == '1')
        {
            return "1";
        }
        else
        {
            return "0";
        }
    }
    string leftUp = quadTree(n/2, x, y);
    string rightUp = quadTree(n/2, x, y + n/2);
    string leftDown = quadTree(n/2, x + n/2, y);
    string rightDown = quadTree(n/2, x + n/2, y + n/2);
    if(leftUp.size() == 1 && rightDown.size() == 1 && leftDown.size() == 1 && leftUp.size() == 1)
    {
        if((leftUp == rightUp) && (rightUp == leftDown) && (leftDown == rightDown))
        {
            return leftUp;
        }
    }
    
    return ("(" +leftUp + rightUp + leftDown+ rightDown + ")");
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << quadTree(n, 1, 1);
}