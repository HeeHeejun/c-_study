#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

vector<int> connect;

int getParent(int index)
{
    if(connect[index] == index) return index;
    return connect[index] = getParent(connect[index]);
}

void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if(a < b) connect[b] = a;
    else connect[a] = b;
}

bool findParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    return false;
}

int minCost(int house, int road)
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    vector<int> result;

    int cost, first, last;
    for(int i = 0; i < road; i++)
    {
        cin >> first >> last >> cost;
        q.push({cost, first, last});
    }

    while(!q.empty())
    {
        tuple<int, int, int> tmp = q.top();
        q.pop();
        cost = get<0>(tmp);
        first = get<1>(tmp);
        last = get<2>(tmp);

        if(!findParent(first, last))
        {
            result.push_back(cost);
            unionParent(first, last);
        }
    }

    int maxIndex = 0;
    for(int i = 0; i < result.size(); i++)
    {
        if(result[maxIndex] < result[i])
        {
            maxIndex = i;
        }
    }

    int anw = 0;
    for(int i = 0; i < result.size(); i++)
    {
        if(i != maxIndex)
        {
            anw += result[i];
        }
    }

    return anw;
}

int main()
{
    int house, road;
    cin >> house >> road;

    connect.resize(house + 1);
    for(int i = 1; i <= house; i++)
    {
        connect[i] = i;
    }

    cout << minCost(house, road);
}