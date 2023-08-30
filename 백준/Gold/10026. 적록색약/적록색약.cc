#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N; // 맵 크기
char map[101][101];
int visit[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int result_cantsee = 0;
int result_cansee = 0;

void bfs(int sx, int sy);
// 적록 색약인 사람
void cantsee()
{
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 'G')
                map[i][j] = 'R';
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j] == 0)
            {
                bfs(i, j);
                result_cantsee++;
            }
        }
    }
}

// 아닌 사람
void cansee()
{
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j] == 0)
            {
                bfs(i, j);
                result_cansee++;
            }
        }
    }
}

void bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visit[sx][sy]++;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (visit[nx][ny] != 0)
                continue;
            if (map[nx][ny] == map[x][y])
            {
                visit[nx][ny]++;
                q.push({nx, ny});
            }
        }
    }
}

void input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
}

int main(void)
{
    input();
    cansee();
    cantsee();

    cout << result_cansee << " " << result_cantsee;
}