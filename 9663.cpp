//(��4) n-queen
//�� n���� ���� ������ �� ���� ��ġ�� ���� ����� ���� ���
//��Ʈ��ŷ

#include <iostream>
using namespace std;

int map[15];
int replaceQueen(int n, int current);
int main()
{
    //���� �ٿ��� �ϳ��� --> ���ٿ� �ϳ��� ��Ÿ�����
    //������ ��ȣ�� �ٸ� ��ȣ�� �����ϸ� �ȴ�.
    //�밢�� ��, [a][b]�� �ְ� ���� [i][j] �̸�  a-i = b-j�̸� �밢����.
    // i-a = b-j�̸� �ȴ�.
    int n;
    cin >> n;
    
    int result = replaceQueen(n, 0);
    cout << result;
}

int replaceQueen(int n, int current)
{
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        map[current] = i;
        bool isPromise = true;
        for(int j = 0; j < current; j++)
        {
            if(map[current] == map[j] || abs(current - j) == abs(map[current] - map[j])) {isPromise = false; break;}
        }
        if(!isPromise) continue;
        if(current == n - 1) {result++; continue;}
        result += replaceQueen(n, current+1);
    }

    return result;
}