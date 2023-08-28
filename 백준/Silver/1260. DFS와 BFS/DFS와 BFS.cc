#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N; // 정점의 개수
int M; // 간선의 개수
int V; // 탐색을 시작할 정점의 번호

vector<int> v[1001];
queue<int> q;

int visit_bfs[1001];
int visit_dfs[1001];
vector<int> result;

void input()
{
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

void dfs(int n)
{
    visit_dfs[n]++;

    cout << n << " ";
    sort(v[n].begin(), v[n].end());
    for (int i = 0; i < v[n].size(); i++)
    {
        int x = v[n][i];
        if (visit_dfs[x] != 0)
            continue;
        dfs(x);
    }
}

void bfs()
{
    q.push(V);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        visit_bfs[x]++;

        cout << x << " ";
        sort(v[x].begin(), v[x].end());
        for (int i = 0; i < v[x].size(); i++)
        {
            int y = v[x][i];

            if (visit_bfs[y] != 0)
                continue;

            q.push(y);
            visit_bfs[y] = visit_bfs[y] + 1;
        }
    }
}

int main(void)
{
    input();
    dfs(V);
    cout << "\n";
    bfs();
}