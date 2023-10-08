// 각 학생마다 최단 거리 구하기 (다익스트라로 구하기)
// 최단 거리 비교해서 누가 제일 긴지 확인
// 단방향으로 주어진 경로들이라 A ->X 까지 가는거면
// A -> X -> A 로 구해야함!

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N; // 학생 수 (마을 수) (1 ≤ N ≤ 1,000)
int M; // 단방향 도로(1 ≤ M ≤ 10,000)
int X; // 파티 마을

int max_time = 0;
int costs[1001];

typedef struct node
{
    int dest;
    int time;
} node;

vector<node> dis[10001];

struct cmp
{
    bool operator()(node a, node b)
    {
        return (a.time > b.time);
    }
};

void input()
{
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        dis[a].push_back({b, t});
    }
}

void init()
{
    for (int i = 1; i <= N; i++)
    {
        costs[i] = 987654321;
    }
}

int dijkstra(int start, int end)
{
    int result = 0;
    priority_queue<node, vector<node>, cmp> pq;
    init();

    pq.push({start, 0});
    costs[start] = 0;

    while (!pq.empty())
    {
        int city = pq.top().dest;
        int time = pq.top().time;
        pq.pop();

        if (city == end)
            return result = costs[city];

        for (int i = 0; i < dis[city].size(); i++)
        {
            int ncity = dis[city][i].dest;
            int ntime = dis[city][i].time;

            if (ntime + time < costs[ncity])
            {
                costs[ncity] = ntime + time;
                pq.push({ncity, ntime + time});
            }
        }
    }

    // 조건 상 일어날 수 없는 경우
    return -1;
}

int main(void)
{
    input();

    for (int i = 1; i <= N; i++)
    {
        int go_time = dijkstra(i, X);
        int back_time = dijkstra(X, i);

        if (go_time == -1 || back_time == -1)
            cout << "도착지에 도달하지 못했습니다.";
        int result = go_time + back_time;

        max_time = max(result, max_time);
    }
    cout << max_time;
}