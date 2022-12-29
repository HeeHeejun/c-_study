//bfs�� �� ���, ������ �湮ǥ�ø� �ϴ� �� ���� �־��� �� �湮üũ�� �ϴ� ���� q�� �޸� �ʰ��� ������ �� �ִ�.
#include <iostream>
#include <queue>
#include <cstring>

struct position
{
    int x;
    int y;
};

using namespace std;
int main()
{
    int testCase, row, col, cabbage;
    int map[50][50] = {0};
    cin >> testCase;
    for(int i = 0; i < testCase; i++)
    {
        cin >> row >> col >> cabbage;
        int count = 0;
        for(int j = 0; j < cabbage; j++)
        {
            position temp;
            cin >> temp.y >> temp.x;
            map[temp.x][temp.y] = 1;
        }   
        position start;
        do
        {
            start = {-1, -1};  
            bool isfind = false;
            for(int j = 0; j < col; j++)
            {
                for(int k = 0; k < row; k++)
                {
                    if(map[j][k] == 1) 
                    {
                        start = {j, k};
                        isfind = true;
                        break;
                    }
                } 
                if(isfind) break;
            }
            map[start.x][start.y] = 2;

            queue<position> q;
            q.push(start);
            while (!q.empty())
            {
                int dx[4] = {0,0,-1,1};
                int dy[4] = {-1,1,0,0};

                position current = q.front();
                q.pop();
                for(int j = 0; j < 4; j++)
                {
                    position next = {current.x + dx[j], current.y + dy[j]};
                    if(next.x >= 0 && next.y >= 0 && next.x < col && next.y < row && map[next.x][next.y] == 1)
                    {
                        map[next.x][next.y] = 2; //�湮�ߴٴ� ǥ��
                        q.push(next);
                    }
                }
            }
            count++;
        }while (start.x != -1 && start.y != -1);

        memset(map, 0, sizeof(map[0][0]) * 50 * 50);
        cout <<  count - 1 << "\n";
    }
}  