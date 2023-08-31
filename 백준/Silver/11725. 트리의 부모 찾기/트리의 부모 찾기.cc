#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[100001];
int N; // 노드의 개수
int visit[100001];

void input()
{
    int x, y;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

void bfs()
{
    queue<int> q;
    q.push(1);
    visit[1]++;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < v[x].size(); i++)
        {
            int nx = v[x][i];
            if (visit[nx] != 0)
                continue;
            visit[nx] = x;
            q.push(nx);
        }
    }
}

int main(void)
{
    input();
    bfs();
    for (int i = 2; i <= N; i++)
    {
        cout << visit[i] << "\n";
    }
}