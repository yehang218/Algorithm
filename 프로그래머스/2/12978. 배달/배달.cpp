// 문제 분석
/*
N개의 마을 (1~N)
연결 길 <- 양방향 통행 가능
각 길마다 걸리는 시간 다름
1번 마을에서 K 시간 이하로 배달 가능한 마을의 개수?

-> dijkstra 사용!
*/

#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

vector<pair<int, int>> info[51]; // 도착 마을, 걸리는 시간
int dist[51]; // 거리 정보 저장

struct node
{
    int start;
    int time;

    bool operator < (const node& n) const{
        return time > n.time;
    }
};

void dijkstra()
{
    priority_queue<node> pq;
    dist[1] = 0;
    pq.push({1, dist[1]});

    while(!pq.empty())
    {
        int start = pq.top().start;
        int time = pq.top().time;
        pq.pop();

        for(int i = 0; i < info[start].size(); i++)
        {
            int dest = info[start][i].first;
            int ntime = info[start][i].second;

            // 지금까지의 거리 + 도착지 거리 > 도착지까지의 거리 보다 크면 그 경우는 pass
            if(dist[start] + ntime >= dist[dest]) continue;
            dist[dest] = dist[start] + ntime;
            pq.push({dest, dist[dest]});
        }
    }
}

void init(int N, vector<vector<int> > road)
{
    fill_n(dist, N + 1, INF);

    for(int i = 0; i < road.size(); i++)
    {
        for(int j = 0; j < road[i].size(); j++)
        {
            info[road[i][0]].push_back({road[i][1], road[i][2]});
            info[road[i][1]].push_back({road[i][0], road[i][2]});
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    init(N, road);
    dijkstra();

    for(int i = 1; i <= N; i++)
    {
        if(dist[i] > K) continue;
        answer++;
    }

    return answer;
}