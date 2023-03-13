// (골2) 1202번
// 그리디 알고리즘
// 우선순위 큐

#include <iostream>
#include <queue>
#include <set>

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> jewel;
multiset<int> backpack;

long long maxValue();
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int jewelNum, backpackNum;
    cin >> jewelNum >> backpackNum;

    for(int i = 0; i < jewelNum; i++)
    {
        pair<int,int> temp;
        cin >> temp.second >> temp.first;
        jewel.push(temp);
    }

    for(int i = 0; i < backpackNum; i++)
    {
        int weight;
        cin >> weight;
        backpack.insert(weight);
    }

    long long result = 0;
    while (!(jewel.empty() || backpack.empty()))
    {
        pair<int, int> temp = jewel.top();
        jewel.pop();

        auto it = backpack.lower_bound(temp.second);
        if(it == backpack.end()) continue;
        result += temp.first;
        backpack.erase(it);
    }
    cout << result;
}
