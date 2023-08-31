#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 컴퓨터의 수
int M; // 연결되어 있는 컴퓨터의 쌍의 수

vector<int> v[101];
queue<int> q;
int visit[101];

void input()
{
    int x, y;

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

int bfs()
{
    int result = 0;
    q.push(1);
    visit[1]++;

    while (!q.empty())
    {
        int virus = q.front();
        q.pop();

        for (int i = 0; i < v[virus].size(); i++)
        {
            int y = v[virus][i];

            if (visit[y] != 0)
                continue;

            q.push(y);
            visit[y]++;
            result++;
        }
    }
    return result;
}

int main(void)
{
    int result = 0;
    input();
    cout << bfs();
}