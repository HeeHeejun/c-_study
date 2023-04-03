//(��4) ����Ŭ ����
//����带 ������ ����Ŭ�� �ִ��� �Ǵ� 
//�и�����, UnionFind �˰���

#include <iostream>
using namespace std;
int parent[500000];

int findParent(int x)
{
    if(x == parent[x]) return x;
    else return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y)
{
    x = findParent(x);
    y = findParent(y);
    
    if(x > y) parent[x] = y;
    else parent[y] = x;
}

int main()
{
    int n, maxTurnCount, i;
    cin >> n >> maxTurnCount;
    for(int i = 0; i < n; i++){parent[i] = i;}
    for(int i = 0; i < maxTurnCount; i++)
    {
        int first, second;
        cin >> first >> second;
        if(findParent(first) == findParent(second)) {cout << i + 1; return 0;}
        unionParent(first, second); 
    }

    cout << 0;
}