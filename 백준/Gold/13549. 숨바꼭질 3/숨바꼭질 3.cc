#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 수빈이의 위치
int K; // 동생 위치

int dx[3] = {-1, 1, 2};
int cost[100001];

struct node
{
    int dest;
    int time;
};

struct cmp
{
    bool operator()(node a, node b)
    {
        return (a.time > b.time);
    }
};

void input()
{
    cin >> N >> K;
}

void init()
{
    for (int i = 0; i <= 100000; i++)
    {
        cost[i] = 987654321;
    }
}
void dijkstra()
{
    priority_queue<node, vector<node>, cmp> pq;
    init();
    pq.push({N, 0});
    cost[N] = 0;

    while (!pq.empty())
    {
        int x = pq.top().dest;
        int t = pq.top().time;
        pq.pop();

        for (int i = 0; i < 3; i++)
        {
            int nx;
            int nt;
            if (i != 2)
            {
                nx = x + dx[i];
                nt = 1;
            }
            else
            {
                nx = x * dx[i];
                nt = 0;
            }

            if (nx < 0 || nx > 100000)
                continue;

            if (t + nt < cost[nx])
            {
                cost[nx] = t + nt;
                pq.push({nx, t + nt});
            }
        }
    }

    cout << cost[K];
}

int main(void)
{
    input();
    dijkstra();
}