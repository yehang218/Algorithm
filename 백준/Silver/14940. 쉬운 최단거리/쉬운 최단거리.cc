#include <iostream>
#include <queue>

using namespace std;

int n, m;               // 지도의 크기  2 ≤ n ≤ 1000, 2 ≤ m ≤ 1000
int map[1001][1001];    // 0 : 갈 수 없는 땅 / 1 : 갈 수 있는 땅 / 2 : 목표 지점
int visit[1001][1001];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int sx, int sy)
{
    queue<pair<int, int>> q;

    // 목표 지점
    visit[sx][sy] = 1;
    q.push({sx, sy});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            // 이미 갔던 곳이라면
            if (visit[nx][ny] != 0)
                continue;

            // 갈 수 없는 땅이라면
            if (map[nx][ny] == 0)
                continue;

            q.push({nx, ny});
            visit[nx][ny] = visit[x][y] + 1;
        }
    }

    visit[sx][sy] = 0;
}

void input()
{
    int num, sx, sy = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            map[i][j] = num;
            if (num == 2)
            {
                sx = i;
                sy = j;
            }
        }
    }
    bfs(sx, sy);
}

void output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && visit[i][j] == 0) visit[i][j] = -1;             // 원래 갈 수있는 땅인데 도달 못한 경우
            else if (visit[i][j] != 0) visit[i][j] -= 1;                          // 0이 아니면 1씩 빼주기 (시작을 1부터 했으므로)

            cout << visit[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void)
{
    input();
    output();
}