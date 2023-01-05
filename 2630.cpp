//(실2) 색종이 만들기
//같은 색의 색종이가 총 몇개인지 출력
//분할 정복

#include <iostream>

using namespace std;
bool colorPaper[128][128];
void divid(int& whiteColor, int& blueColor, int n, pair<int, int> start);
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            bool color;
            cin >> color;
            colorPaper[i][j] = color;
        }
    }
    
    int w = 0, b = 0;
    divid(w, b, n ,{0, 0});
    cout << w << "\n" << b;
}

void divid(int& whiteColor, int& blueColor, int n, pair<int, int> start)
{
    if(n == 0)
    {
        if(colorPaper[start.first][start.second]) blueColor++;
        else whiteColor++;
        return;
    }

    bool isNext = false;
    bool temp = colorPaper[start.first][start.second];
    for(int i = start.first; i < start.first + n; i++)
    {
        for(int j = start.second; j < start.second + n; j++)
        {
            if (temp != colorPaper[i][j]){isNext = true; break;}
        }
        if(isNext) break;
    }
    
    if(!isNext)
    {
        if(temp) blueColor++;
        else whiteColor++;
        return;
    }

    int dx[4] = {0, n/2, 0 , n/2};
    int dy[4] = {0, 0, n/2, n/2};
    for(int i = 0; i < 4; i++)
    {
        divid(whiteColor, blueColor, n/2, {start.first + dx[i], start.second + dy[i]});
    }   
}