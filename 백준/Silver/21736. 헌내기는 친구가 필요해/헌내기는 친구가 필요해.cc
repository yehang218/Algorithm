#include <iostream>
#include <queue>

using namespace std;

int N, M; // 캠퍼스의 크기
int map[601][601];
int visit[601][601] = {
    0,
};
int result = 0;

queue<pair<int, int>> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;

            if (c == 'I')
            {
                q.push({i, j});
                visit[i][j]++;
            }
            else if (c == 'X')
                map[i][j] = 1; // 벽
            else if (c == 'P')
                map[i][j] = 2; // 사람
        }
    }
}

void solve()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (visit[nx][ny] > 0)
            {
                continue;
            }

            if (map[nx][ny] == 1)
                continue;

            else if (map[nx][ny] == 2)
            {
                map[nx][ny] = 0;
                result++;
            }

            visit[nx][ny]++;
            q.push({nx, ny});
        }
    }
}

int main(void)
{
    input();
    solve();
    if (result != 0)
        cout << result;
    else
        cout << "TT";
}