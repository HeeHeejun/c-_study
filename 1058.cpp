//(��2) ģ��
// �Ѵٸ� �ǳʴ� ģ���� ģ���� ���� ���� ���� ū ���� ���
//�׷���Ž��

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool twoFriend[50][50];
vector<vector<int>> adjList;
int main()
{
    int n, max = 0; cin >> n;
    adjList.resize(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char isFriend; cin >> isFriend;
            if(isFriend == 'Y') adjList[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++)
    {
        int result = 0;
        for(auto direct = adjList[i].begin(); direct != adjList[i].end(); direct++)
        {
            if(twoFriend[i][*direct] != true) {twoFriend[i][*direct] = true; result++;}
            for(auto indirect = adjList[*direct].begin(); indirect != adjList[*direct].end(); indirect++)
            {
                if(i != *indirect && twoFriend[i][*indirect] != true) {twoFriend[i][*indirect] = true; result++;}
            }
        }
        
        if(result > max) max = result;
    }

    cout << max;
}

