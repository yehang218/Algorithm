#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int V; // 정점의 개수
int E; // 간선의 개수
int K; // 시작 정점의 번호

vector<pair<int, int>> vec[300001]; // 비용, 노드
// 지금까지 걸린 최소 비용, 방문할 노드 (첫 번째 인자 기준으로 오름차순 정렬)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 비용, 노드

int costs[20001];

void Input()
{
    cin >> V >> E;
    cin >> K;

    for (int i = 1; i <= V; i++)
    {
        costs[i] = INF;
    }

    for (int i = 0; i < E; i++)
    {
        int u, v, w; // u -> v 가중치 w
        cin >> u >> v >> w;
        vec[u].push_back({w, v});
    }

    pq.push({0, K});
    costs[K] = 0;
}

void Dijkstra()
{
    while (!pq.empty())
    {
        int qcost = pq.top().first;  // 현재 있는 노드의 최소 비용
        int qnode = pq.top().second; // 현재 있는 노드 위치
        pq.pop();

        if (costs[qnode] < qcost)
            continue;

        for (int i = 0; i < vec[qnode].size(); i++)
        {
            int ncost = vec[qnode][i].first;  // 다음 노드까지 가는데 드는 비용
            int nnode = vec[qnode][i].second; // 다음 노드 번호

            if (ncost + qcost < costs[nnode])
            {
                costs[nnode] = ncost + qcost;
                pq.push({ncost + qcost, nnode});
            }
        }
    }
}

int main(void)
{
    Input();
    Dijkstra();

    for (int i = 1; i <= V; i++)
    {
        if (costs[i] == INF)
            cout << "INF"
                 << "\n";
        else
            cout << costs[i] << "\n";
    }
}