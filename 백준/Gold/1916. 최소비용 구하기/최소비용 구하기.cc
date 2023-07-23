#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int start, des;
int costs[1001];
int answer;

vector<pair<int, int>> v[1001]; // 비용, 경로

bool visit[1001];

typedef struct node
{
    int cost; // 지금까지 걸린 최소 비용
    int city; // 현재 위치
} node;

struct cmp
{
    bool operator()(node a, node b)
    {
        return (a.cost > b.cost); // pq : true일 경우 둘의 위치를 바꿈
    }
};

priority_queue<node, vector<node>, cmp> pq;

void input()
{
    cin >> N; // 도시의 개수
    cin >> M; // 버스의 개수

    for (int i = 1; i <= N; i++)
    {
        costs[i] = 2147483647;
    }

    for (int i = 0; i < M; i++)
    {
        int from;
        int to;
        int cost;

        cin >> from >> to >> cost;
        v[from].push_back({cost, to}); // 비용, 경로 저장
    }

    cin >> start >> des;
}

void find_cost()
{
    pq.push({0, start});
    visit[start] = true;

    while (!pq.empty())
    {
        int qcost = pq.top().cost; // 지금 도시까지 온 비용
        int qcity = pq.top().city; // 지금 도시
        pq.pop();
        visit[qcity] = true;

        if (qcity == des)
            return;

        if (costs[qcity] < qcost)
            continue;

        for (int i = 0; i < v[qcity].size(); i++)
        {
            int nextcity = v[qcity][i].second; // 다음 도시
            int nextcost = v[qcity][i].first;  // 다음 도시까지 가는 데 필요한 비용

            if (visit[nextcity])
                continue;

            if (nextcost + qcost < costs[nextcity])
            {
                costs[nextcity] = qcost + nextcost;
                pq.push({qcost + nextcost, nextcity});
            }
        }
    }
}

int main(void)
{
    input();
    find_cost();
    cout << costs[des];
}