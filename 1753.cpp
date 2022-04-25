// 백준 1753번, 최단경로
// 방향그래프가 주어지면 시작점에서 다른 모든 정점으로의 최단 경로를 구해주는 프로그램
// "다익스트라 알고리즘"을 이용한 최소비용 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(int start_, int point_, int lineNum_);

// 함수를 이용한 방법
int main()
{
    int start, point, lineNum;
    cin >> point >> lineNum >> start;

    dijkstra(start, point, lineNum);

    return 0;
}

void dijkstra(int start_, int point_, int lineNum_)
{
    int INF = 100000000;
    vector<pair<int,int>> trunk[point_ + 1]; //간선의 정보 저장
    int lowCost[point_ + 1]; // 최소비용 저장
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //조사하는 점에서의 간선을 조사하기 위한 pq (조사할 때, 비용이 가장 적은 점을 보기 위함)
    
    for(int i = 1; i <= point_; i++)
    {
        lowCost[i] = INF;
    }
    
    for(int i = 0; i < lineNum_; i++)
    {
        int first, last, Distance;
        cin >> first >> last >> Distance;
        trunk[first].push_back(make_pair(Distance, last));
    }

    lowCost[start_] = 0;
    pq.push(make_pair(0, start_));

    while(!pq.empty())
    {
        int Cost = pq.top().first;
        int corrent = pq.top().second;
        pq.pop();
        if(Cost > lowCost[corrent])
            continue;
        for(int i = 0; i < trunk[corrent].size(); i++)
        {
            int next = trunk[corrent][i].second;
            int nextCost = trunk[corrent][i].first + Cost;
            if(nextCost < lowCost[next])
            {
                lowCost[next] = nextCost;
                pq.push(make_pair(nextCost, next));
            }
        }
    }

    for(int i = 1; i <= point_; i++)
    {
        if(lowCost[i] == INF)
            cout << "INF" << "\n";
        else
            cout << lowCost[i] << "\n";
    }
}


/*  함수를 이용하지 않은 방법


int main()
{
    int point, l, start, INF = 1000000000; //point : 정점의 수, l : 간선의 수, start : 시작점의 번호, INF : 무한대를 나타내기 위한 변수

    cin >> point >> l >> start; // 정점과 간선의 개수, 시작점을 입력받음
    
    vector<pair <int, int>> line[point + 1]; //간선의 정보를 저장하는 vector
    int lowCost[point + 1]; // 노드로가는 최소비용을 저장하는 배열

    for(int i = 0; i < l; i++)
    {
        int first, last, Distance; // first : 간선의 출발점, last : 간선의 도착점, Distance : 간선간의 비용
        cin >> first >> last >> Distance; // 간선의 정보를 입력받음
        line[first].push_back(make_pair(Distance, last)); // 간선의 시작점과 배열의 인덱스를 같게하고 거기에 비용과 도착점의 정보를 저장함
    }

    //모든 최소비용을 초기값을 INF로 초기화
    for(int i = 1; i <= point; i++)
    {
        lowCost[i] = INF;
    }

    lowCost[start] = 0; //시작점의 최소비용을 0으로 함
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq; // 노드 방문을 위한, "다익스트라 알고리즘"을 위한 우선순위 큐
    pq.push(make_pair(0, start)); // 우선순위큐에 먼저 시작점을 입력함
    
    while(!pq.empty())
    {
        int cost = pq.top().first; // 현재 번호까지의 비용을 저장       
        int corrent = pq.top().second; // 시작점의 번호, 현재의 번호를 입력함
        pq.pop();

        // 만약 그 번호의 비용이, 최소비용보다 작다면 건너뜀
        if(lowCost[corrent] < cost)
            continue;
        
        // 현재의 번호에서의 간선의 정보를 확인함
        for(int i = 0; i < line[corrent].size(); i++)
        {
            int next = line[corrent][i].second;
            int nextCost = line[corrent][i].first + lowCost[corrent];
            if(nextCost < lowCost[next])
            {
                lowCost[next] = nextCost;
                pq.push(make_pair(nextCost, next));
            }   
        }
    }

    for(int i = 1; i <= point; i++)
    {
        if(lowCost[i] == INF)
        {
            cout << "INF" << "\n";
            continue;
        }
        cout  << lowCost[i] << "\n";
    }
    return 0;
}
*/