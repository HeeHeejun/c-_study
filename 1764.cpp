#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,m;
    unordered_set<string> us;
    set<string> result;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        us.insert(name);
    } 

    for(int i = 0; i < m; i++)
    {
        string name;
        cin >> name;
        auto it = us.find(name);
        if(it != us.end()) result.insert(*it);
    }

    cout << result.size() << "\n";
    for(auto it = result.begin(); it != result.end(); it++) cout << *it << "\n";
}