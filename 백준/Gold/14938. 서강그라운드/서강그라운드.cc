// 경로 담기
// 각 지역까지의 최단 경로 구하기 -> 다익스트라
// 2->1->4 일때면 4까지의 경로 쭉쭉 구하기
// 그 지역까지 가는데 경로 길이가 m을 넘으면 itme 개수는 더 구하지 않고 멈추기
// 그 지역까지 가면서 item 개수 계속 더하기

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n; // 지역의 개수 (1 <= n <= 100)
int m; // 수색 범위 (1 <= m <= 15)
int r; // 길의 개수(1<=r <= 100)

int t[101]; // 아이템의 수 (1<=t<=30) ... 배열의 크기는 지역의 개수만큼이니까 101개까지 선언해줘야함...ㅠㅠ

int max_item = 0; // 얻을 수 있는 아이템의 최대 개수
int cost[101];    // 해당 위치까지 도달하는데 걸리는 최소 길이 저장

typedef struct node
{
    int dest; // 도착지
    int len;  // 길의 길이
} node;

vector<node> dis[101]; // 경로

struct cmp
{
    bool operator()(node a, node b)
    {
        return (a.len > b.len);
    }
};

void input()
{
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int j = 0; j < r; j++)
    {
        int a, b, i; // 지역 변호 a, b / 길의 길이 i
        cin >> a >> b >> i;

        // 양방향 통행 가능
        dis[a].push_back({b, i});
        dis[b].push_back({a, i});
    }
}

// cost 배열 987654321로 초기화
void init()
{
    for (int i = 1; i <= n; i++)
    {
        cost[i] = 987654321;
    }
}

int dijkstra(int start)
{
    priority_queue<node, vector<node>, cmp> pq;
    init();

    cost[start] = 0;
    pq.push({start, 0});

    while (!pq.empty())
    {
        int city = pq.top().dest;
        int len = pq.top().len;
        pq.pop();

        for (int i = 0; i < dis[city].size(); i++)
        {
            int ncity = dis[city][i].dest; // 다음 도시
            int nlen = dis[city][i].len;   // 다음 도시까지 가는데 드는 비용

            // 기존 경로보다 더 짧고 && 수색 범위 이하면
            if (nlen + len < cost[ncity] && nlen + len <= m)
            {
                cost[ncity] = nlen + len;
                pq.push({ncity, nlen + len});
            }
        }
    }

    int item = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cost[i] <= m)
            item = item + t[i];
    }

    // cout << start << " " << item << "\n";
    return item;
}

int main(void)
{
    input();
    for (int i = 1; i <= n; i++)
    {
        int item = dijkstra(i);
        max_item = max(item, max_item);
    }
    cout << max_item;
}