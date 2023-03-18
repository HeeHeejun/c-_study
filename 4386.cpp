//(골3) 별자리 만들기
// 별의 x, y 좌표가 주어지면 모든 별을 이은 것의 최소 비용을 구하라
// 최소 스패닝 트리, prim 알고리즘

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

struct star
{
    double x, y;
};

vector<star> stars;
vector<vector<pair<double, int>>> adjList;
bool visit[100] = {false};

void leastCost();

int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        star temp;
        cin >> temp.x >> temp.y;
        stars.push_back(temp);
    }

    adjList.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int temp = sqrt(pow(stars[i].x - stars[j].x, 2) + pow(stars[i].y - stars[j].y, 2)) * 100;
            double cost = temp/100.0;
            adjList[i].push_back({cost, j});
            adjList[j].push_back({cost, i});
        }
    }
    
    leastCost();
}

void leastCost()
{
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0,0});

    double cost = 0;

    while(!pq.empty())
    {
        pair<double, int> current = pq.top();
        pq.pop();
        
        if(visit[current.second]) continue;
        visit[current.second] = true;
        cost += current.first;
        for(int i = 0; i < adjList[current.second].size(); i++)
        {
            pair<double, int> next = adjList[current.second][i];
            
            if(!visit[next.second])
            {
                pq.push(next);
            }
        }
    }

    cout << cost;
}


