// (골4) 거짓말
// 진실을 알고있는 사람이 없는 파티가 총 몇개인지 출력
// union-find

#include <iostream>
#include <vector>

using namespace std;

int parent[51] = {};

int getParent(int x);
void unionParent(int x, int y);
bool find(int x, int y);

int main()
{
    int person, partyNum, knowTruth, knowPerson = 0, result = 0;
    vector<vector<int>> party;
    cin >> person >> partyNum >> knowTruth;

    for(int i = 0; i <= person; i++){ parent[i] = i; }
    if(knowTruth != 0) cin >> knowPerson;
    for(int i = 0; i < knowTruth - 1; i++)
    {
        int temp;
        cin >> temp;
        unionParent(knowPerson, temp);
    }
    
    party.resize(partyNum);
    for(int i = 0; i < partyNum; i++)
    {
        int partyPerson, firstMan;
        cin >> partyPerson >> firstMan;
        party[i].push_back(firstMan);
        for(int j = 0; j < partyPerson - 1; j++)
        {
            int temp;
            cin >> temp;
            unionParent(firstMan, temp);
            party[i].push_back(temp);
        }
    }

    for(int i = 0; i < partyNum; i++)
    {
        bool canLie = true;
        for(int j = 0; j < party[i].size(); j++)
        {
            if(find(knowPerson, party[i][j])){canLie = false; break;}
        }
        if(canLie) result++;
    }

    cout << result;
}

int getParent(int x)
{
    if(parent[x] == x) return x;
    return getParent(parent[x]);
}

void unionParent(int x, int y)
{
    x = getParent(x);
    y = getParent(y);

    if(x == y) return;
    
    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool find(int x, int y)
{
    x = getParent(x);
    y = getParent(y);
    if(x==y) return true;
    else return false;
}