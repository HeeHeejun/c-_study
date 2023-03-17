// (골3) 텀프로젝트
// 서로 이어져 있지 않은 학생의 수를 구하라
// union-find

#include <iostream>
#include <stack>
using namespace std;

int choice[100001];
int visit[100001];

int main()
{
    int testCase; cin >> testCase;
    while(testCase--)
    {
        int n; cin >> n;
        int result = 0;
        stack<int> stk;
        for(int i = 1; i <= n; i++)
        {
            cin >> choice[i];
            visit[i] = 0;
        }

        for(int i = 1; i <= n; i++)
        {
            int from = i, to = choice[i];
            if(visit[from] != 0) continue;
            visit[from] = 1;
            stk.push(from);
            
            while(!(from == to || visit[to] != 0))
            {
                stk.push(to);
                visit[to] = visit[from] + 1;
                from = to;
                to = choice[from];
            }
            
            if(from == to) result++;
            else if(visit[to] != -1) result = result + visit[from] - visit[to] + 1;

            while(!stk.empty())
            {
                visit[stk.top()] = -1;
                stk.pop();
            }
        }
        cout << n - result << "\n";
    }
}