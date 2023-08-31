// 1-> 이동 o / 0 -> 이동 x
#include <iostream>
#include <queue>

using namespace std;

int N, M; // 미로의 크기
queue<pair<int, int>> q;
int map[101][101];
int visit[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void input()
{
    char c;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> c;
            map[i][j] = c - '0';
        }
    }
}

void bfs()
{
    q.push({0, 0});
    visit[0][0]++;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1)
                continue;
            if (visit[nx][ny] != 0)
                continue;
            if (map[nx][ny] == 0)
                continue;

            q.push({nx, ny});
            visit[nx][ny] = visit[x][y] + 1;

            if (nx == N - 1 && ny == M - 1)
            {
                cout << visit[nx][ny];
                return;
            }
        }
    }
}

int main(void)
{
    input();
    bfs();
}