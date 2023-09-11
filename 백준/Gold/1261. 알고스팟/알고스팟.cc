// 최단 경로로 가는 것이 아니라 최소 벽을 뚫는 것이 목표!
// -> 벽을 뚫은 횟수를 저장
// -> 전의 경우가 더 적게 뚫었다면 전의 것으로 저장(좀 돌아가더라도 적게 뚫은걸 선택)
#define INF 987654321

#include <iostream>
#include <queue>

using namespace std;

int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int map[101][101];
int cost[101][101];
queue<pair<int, int>> q;

void output()
{
    cout << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << "\n";
    }
}

void input()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            map[i][j] = c - '0';
            cost[i][j] = INF;
        }
    }
}

void solve()
{
    q.push({0, 0});
    cost[0][0] = 0;

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

            if (map[nx][ny] == 0)
            {
                if (cost[nx][ny] > cost[x][y])
                {
                    cost[nx][ny] = cost[x][y];
                    q.push({nx, ny});
                }
            }

            else if (map[nx][ny] == 1)
            {
                if (cost[nx][ny] > cost[x][y] + 1)
                {
                    cost[nx][ny] = cost[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(void)
{
    input();
    solve();
    // output();
    cout << cost[N - 1][M - 1];
}