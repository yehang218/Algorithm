#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N;
int M;
int room[9][9];
int copy_room[9][9];

int count_zero = 0; // 안전 영역 수

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

queue<pair<int, int>> q;

void move_virus();
void bfs();
void check_zero();

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> room[i][j];
        }
    }
}

// 벽 세우는 함수 -> 재귀 사용 안하고 하는 방법은 복잡하거나 없는듯..
void build_wall(int count_wall)
{
    if (count_wall == 3)
    {
        memcpy(&copy_room, &room, sizeof(room));
        move_virus();
        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (room[i][j] == 1 || room[i][j] == 2)
                continue;

            room[i][j] = 1;
            build_wall(count_wall + 1);
            room[i][j] = 0;
        }
    }
}

// 바이러스 퍼지기
void move_virus()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (copy_room[i][j] == 2)
            {
                q.push({i, j});
                bfs();
            }
        }
    }
    check_zero();
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
            int cx = x + dx[i];
            int cy = y + dy[i];

            // 맵 밖일 경우
            if (cx >= N || cy >= M)
                continue;
            if (cx < 0 || cy < 0)
                continue;

            if (copy_room[cx][cy] == 0)
            {
                copy_room[cx][cy] = 2;
                q.push({cx, cy});
            }
        }
    }
/*
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << copy_room[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n"
         << "\n";
*/
}

// 안전 영역 수 세기
void check_zero()
{
    int zero = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (copy_room[i][j] == 0)
                zero++;
        }
    }

    count_zero = max(count_zero, zero);
}

int main(void)
{
    input();
    build_wall(0);

    cout << count_zero;
}