#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    unordered_map<string, int> nameToNum;
    unordered_map<int, string> numToName;
    int n, question;


    cin >> n >> question;
    for(int i = 1; i <= n; i++)
    {
        string name;
        cin >> name;
        nameToNum[name] = i;
        numToName[i] = name;
    }

    for(int i = 0; i < question; i++)
    {
        string q;
        cin >> q;
        if(q[0] >= '0' && q[0] <= '9') cout << numToName[stoi(q)] << "\n";
        else cout << nameToNum[q] << "\n";
    }
}