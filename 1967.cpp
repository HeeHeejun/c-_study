#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> Node[10001];
vector<bool> visit(10001, false);
int result = 0;
int endNum = 0;

void dfs(int num, int weight)
{
    if(visit[num]) return;
    
    visit[num] = true;

    if(weight > result)
    {
        result = weight;
        endNum = num;
    }

    for(int i = 0; i < Node[num].size(); i++)
    {
        dfs(Node[num][i].first, weight + Node[num][i].second);
    }
}

int main()
{
    int  size;
    cin >> size;

    for(int i = 0; i < size-1; i++)
    {
        int start, next, weight;
        cin >> start >> next >> weight;
        Node[start].push_back({next, weight});
        Node[next].push_back({start, weight});
    }
    
    dfs(1, 0); //끝점 찾기

    visit.assign(10001, false);

    dfs(endNum, 0); // 끝점으로 부터 지름 찾기

    cout << result;
}
