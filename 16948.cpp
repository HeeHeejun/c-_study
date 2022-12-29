#include <iostream>
#include <queue>

int map[200][200];

using namespace std;
struct position
{
    int x;
    int y;
};

int deathNight(int n, position start, position dest);

int main()
{
    int n, result;
    position start, destination;

    cin >> n >> start.x >> start.y >> destination.x >> destination.y;

    result = deathNight(n, start, destination);
    
    cout << result << "\n";

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << map[i][j];
    //     }
    //     cout << "\n";
    // }

    return 0;
}

int deathNight(int n, position start, position dest)
{
    queue<position> q;
    q.push(start);
    map[start.x][start.y] = 1;
    bool isFind = false;

    int dx[6] = {-2,-2,0,0,2,2};
    int dy[6] = {-1,1,-2,2,-1,1};
    while (!q.empty())
    {
        position current = q.front();
        q.pop();

        if(dest.x == current.x && dest.y == current.y)
        {
            return map[current.x][current.y] - 1;
        }

        for(int i = 0; i < 6; i++)
        {
            position next = {current.x + dx[i], current.y + dy[i]};
            
            if( next.x >= 0 && next.y >= 0 && next.x < n && next.y < n && !map[next.x][next.y])
            {
                map[next.x][next.y] = map[current.x][current.y] + 1;
                //cout << "current: "<<current.x << " , "<<current.y << " next : " <<next.x << " , " << next.y << "\n";
                q.push(next);
            }
        }        
    }

    return -1;
}