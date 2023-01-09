//(실1) 단지번호 붙이기
// 붙어있는 단지가 총 몇 단지인지 또, 각 단지의 숫자를 오름차순으로 출력
// 그래프 탐색

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
bool map[25][25];
void numbering(int n);
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char temp;
            bool tempC;
            cin >> temp;
            if(temp == '0') tempC = false;
            else tempC = true;
            map[i][j] = tempC;
        }
    }

    numbering(n);
}

void numbering(int n)
{
    bool visit[25][25] = {false};
    pair<int, int> start;
    bool theEnd = false;
    int result = 0;
    vector<int> number;
    while(!theEnd)
    {
        int tempNumber = 1;
        theEnd = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!visit[i][j] && map[i][j])
                {
                    start = {i, j};
                    theEnd = false;
                    break;
                }
            }
        }

        if(theEnd) break;

        queue<pair<int, int>> q;
        q.push(start);
        visit[start.first][start.second] = true;

        while(!q.empty())
        {
            pair<int, int> current = q.front();
            q.pop();
            int dx[4] = {0,0,1,-1};
            int dy[4] = {1,-1,0,0};

            for(int i = 0; i < 4; i++)
            {
                pair<int, int> next = {current.first + dx[i], current.second + dy[i]};
                if(next.first >= 0 && next.first < n && next.second >= 0 && next.second < n && !visit[next.first][next.second] && map[next.first][next.second])
                {
                    q.push(next);
                    visit[next.first][next.second] = true;
                    tempNumber++;
                }
            }
        }
        result++;
        number.push_back(tempNumber);
    }

    cout << result << "\n";
    sort(number.begin(), number.end());
    for(auto num : number)
    {
        cout << num << "\n";
    }   
}