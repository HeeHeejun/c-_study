#include <iostream>

using namespace std;

int paper[2187][2187];
int result[3] = {0, 0, 0};
int dx[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
int dy[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
void byThree(pair<int, int> start, int n);
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            int temp;
            cin >> temp;
            paper[i][j] = temp;
        }
    }

    byThree({0,0},n);
    for(int i = 0; i < 3; i++){cout<< result[i] << "\n";}
}

void byThree(pair<int, int> start, int n)
{
    if(n == 0){result[paper[start.first][start.second]+1]++;}
    
    int temp = paper[start.first][start.second];
    bool isSame = true;
    for(int i = start.first; i < start.first + n; i++)
    {
        for(int j = start.second; j < start.second + n; j++)
        {
            if (temp != paper[i][j]){ isSame = false; break; }
        }
        if(!isSame) break;
    }
    if(isSame) {result[temp + 1]++; return;}
    for(int i = 0; i < 9; i++){ byThree({start.first + n * dx[i] / 3, start.second + n * dy[i] / 3}, n/3); }
}