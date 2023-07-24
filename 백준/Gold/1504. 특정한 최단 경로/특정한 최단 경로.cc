#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;

int N;      // 정점의 개수
int E;      // 간선의 개수
int v1, v2; // 반드시 거쳐야 하는 정점

vector<pair<int, int>> vec[200001]; // 노드, 비용
int costs[801];

void Input()
{
    int a, b, c;
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c; // a->b, b->a, 비용 c
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }
    cin >> v1 >> v2;
}

void Init()
{
    // 초기화
    for (int i = 1; i <= N; i++)
    {
        costs[i] = INF;
    }
}

void Dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 노드, 비용

    Init();
    pq.push({start, 0});
    costs[start] = 0;

    while (!pq.empty())
    {
        int qnode = pq.top().first;
        int qcost = pq.top().second;
        pq.pop();

        if (qcost > costs[qnode])
            continue;

        for (int i = 0; i < vec[qnode].size(); i++)
        {
            int nnode = vec[qnode][i].first;
            int ncost = vec[qnode][i].second;

            if (ncost + qcost < costs[nnode])
            {
                costs[nnode] = ncost + qcost;
                pq.push({nnode, ncost + qcost});
            }
        }
    }
}

int main(void)
{
    Input();

    int result = 0; // 1->v1->v2->N 또는 1->v2->v1->N

    // 1에서 시작하는 Dijkstra (1->v1 최소 거리, 1->v2 최소 거리)
    Dijkstra(1);
    int one_v1_costs = costs[v1];
    int one_v2_costs = costs[v2];

    // v1에서 시작하는 Dijkstra(v1->v2 최소 거리, v1-> N 최소 거리)
    Dijkstra(v1);
    int v1_v2_costs = costs[v2];
    int v1_N_costs = costs[N];

    // v2에서 시작하는 Dijkstra(v2->N 최소 거리)
    Dijkstra(v2);
    int v2_N_costs = costs[N];

    result = one_v1_costs + v1_v2_costs + v2_N_costs;              // 1->v1->v2->N
    result = min(result, one_v2_costs + v1_v2_costs + v1_N_costs); // 1->v1->v2->N 와 1->v2->v1->N 중 작은 수

    if (result < one_v2_costs + v1_v2_costs + v1_N_costs)
    { // 1->v1->v2->N
        if (one_v1_costs == INF || v1_v2_costs == INF || v2_N_costs == INF)
            cout << "-1";
        else
            cout << result;
    }
    else
    { // 1->v2->v1->N
        if (one_v2_costs == INF || v1_v2_costs == INF || v1_N_costs == INF)
            cout << "-1";
        else
            cout << result;
    }
}