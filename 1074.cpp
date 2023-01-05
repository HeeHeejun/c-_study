#include <iostream>
#include <math.h>

using namespace std;

int visitNum(int n, int targetX, int targetY);

int main()
{
    int n, targetX, targetY, result;
    cin >> n >> targetX >> targetY;

    result = visitNum(n, targetX, targetY);
    cout << result;
}

int visitNum(int n, int targetX, int targetY)
{
    // cout << "n : " << n << " x : " << targetX << " y : " << targetY << "\n"; 
    int row = pow(2, n), col = row, halfRow = row/2, halfCol = col/2;
    int quadrant = 0;
    if(n == 0) return 0;

    if(targetX < row / 2) row = halfRow;
    if(targetY < col / 2) col = halfCol;
    //if(targetY == -1) return 0;
    // cout << "row : " << row << " column : " << col  << "\n"; 

    if(halfCol == col)
    {
        if(halfRow != row) 
        {
            quadrant = 2;
            targetX -= halfRow;     
        }
    }
    else
    {
        if(halfRow == row) 
        {
            quadrant = 1;
            targetY -= halfCol;
        }
        else 
        {
            quadrant = 3;
            targetX -= halfRow; 
            targetY -= halfCol;
        }
    }
    int nextN = n - 1;
    // cout << "quadrant : " << quadrant  << "\n"; 
    // cout << "num : "<<quadrant * pow(2, 2*n - 2) << "\n";
    return quadrant * pow(2, 2*n - 2) + visitNum(nextN, targetX, targetY);
}