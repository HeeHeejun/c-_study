#include <iostream>
#include <queue>

using namespace std;
char matrix[101][101];
int result = 0;
queue<pair<int, int>> q;

void newDoor(int x, int y, vector<pair<int,int>>& door, vector<char>& key)
{
    for(int i = 0; i < key.size(); i++)
    {
        if(toupper(key[i]) == matrix[x][y])
        {
            matrix[x][y] = '.';
            q.push({x, y});
            return;
        }
    }
    door.push_back({x, y});
}

void newKey(int x, int y, vector<pair<int,int>>& door, vector<char>& key)
{
    for(int i = 0; i < door.size(); i++)
    {
        if(toupper(matrix[x][y]) == matrix[door[i].first][door[i].second])
        {
            matrix[door[i].first][door[i].second] = '.';
            q.push({door[i].first, door[i].second});
        }
    }
    key.push_back(matrix[x][y]);
    matrix[x][y] = '.';
    q.push({x,y});
}

void classifyPoint(int x, int y, vector<pair<int,int>>& door, vector<char>& key)
{
    if(matrix[x][y] == '.')
    {
        q.push({x, y});
    }
    else if( 'A'<= matrix[x][y] && matrix[x][y] <= 'Z')
    {
        newDoor(x, y, door, key);
    }
    else if( 'a' <= matrix[x][y] && matrix[x][y]<= 'z')
    {
        newKey(x, y, door, key);
    }
    else if(matrix[x][y] == '$')
    {
        matrix[x][y] = '.';
        q.push({x,y});
        result++;
    }
}

void findDocument(int column, int row, string allKey)
{
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1 , 0, 0};
    vector<pair<int, int>> door;
    vector<char> key;
    bool visit[101][101] = {false};

    //key를 저장시킴
    for(int i = 0; i < allKey.size(); i++)
    {
        if(allKey.compare("0") == 0)
        {
            break;
        }
        key.push_back(allKey[i]);
    }

    // 출발점을 조사
    // (column, x) x <= row
    // (1, x) x <= row
    for(int i = 1; i <= row; i++)
    {
        classifyPoint(1, i, door, key);
        classifyPoint(column, i, door, key);
    }

    // (x, row) x <= column
    // (x, 1) x <= column
    for(int i = 1; i <= column; i++)
    {
        classifyPoint(i, row, door, key);
        classifyPoint(i, 1, door, key);
    }

    for(int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < door.size(); j++)
        {
            if(toupper(key[i]) == matrix[door[j].first][door[j].second])
            {
                q.push({door[j].first, door[j].second});
                matrix[door[j].first][door[j].second] = '.';
            }
        }
    }

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(visit[x][y]) continue;
        visit[x][y] = true;
        // cout << x << ", " << y << "\n";

        for(int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if(nextX < 1 || nextY < 1 || nextX > column || nextY > row) continue;

            classifyPoint(nextX, nextY, door, key);
        }
    }

    cout << result << "\n";
}

int main()
{
    int testCase;
    cin >> testCase;

    for(int i = 0; i < testCase; i++)
    {
        int column, row;
        cin >> column >> row;

        for(int j = 1; j <= column; j++)
        {
            for(int k = 1; k <= row; k++)
            {
                cin >> matrix[j][k];
            }
        }

        string allKey;
        cin >> allKey;

        findDocument(column, row, allKey);
        result = 0;
    }
}