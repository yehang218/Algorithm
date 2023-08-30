#include <iostream>
#include <queue>

using namespace std;

int N, M;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int map[1001][1001];
queue<pair<int, int>> q;
int day;

void input()
{
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }
}

void bfs()
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
            if (map[nx][ny] == 0)
            {
                map[nx][ny] = map[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void check_tomato()
{
    day = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                cout << "-1\n";
                return;
            }
            if (day < map[i][j])
                day = map[i][j];
        }
    }
    cout << day - 1;
}

int main(void)
{
    input();
    bfs();
    check_tomato();
}