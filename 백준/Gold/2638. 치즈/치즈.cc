// 빙산이랑 비슷한 느낌..?
// 1. 내부에 있는 공기는 어떻게 판단하지?
// -> 빙산이랑 접근을 좀 다르게 해야함
// -> 가장자리는 무조건 외부 공기이므로 가장자리 칭구들이 만나는 공기는 모두 외부 공기임!
// -> 치즈를 벽이라고 생각하고 bfs돌리기
// -> 가장자리가 만나는 공기는 2로 바꾸고 2를 두개 이상 만나는 치즈 확인!
// -> 바뀐 치즈들을 가지고도 외부 공기 칭구들 찾아야함
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N; // 세로 격자의 수
int M; // 가로 격자의 수

int map[101][101];
queue<pair<int, int>> q_cheese;
queue<pair<int, int>> q_melting_cheese;
queue<pair<int, int>> q_next_cheese;
queue<pair<int, int>> q_air;
int cheese_visit[101][101];
int air_visit[101][101];
int year = 0;
int melt_count = 0;
int origin_cheese_count = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool check_all_melt();
void bfs();
void melt_cheese();
void find_outside_air();

void output()
{
    cout << "\n";
    cout << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void input()
{
    cin >> N >> M; // 모눈종이 크기

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                q_cheese.push({i, j});
                origin_cheese_count++;
            }
        }
    }
}

void melt_cheese()
{
    while (1)
    {
        find_outside_air();
        bfs();
        year++;

        if (check_all_melt()) // 모두 녹았다면
        {
            cout << year << "\n";
            return;
        }

        q_cheese = q_next_cheese;
        q_next_cheese = queue<pair<int, int>>();
        q_melting_cheese = queue<pair<int, int>>();
    }
}

void bfs()
{
    memset(cheese_visit, 0, sizeof(cheese_visit));

    while (!q_cheese.empty())
    {
        int contact_air = 0;
        int x = q_cheese.front().first;
        int y = q_cheese.front().second;
        cheese_visit[x][y]++;

        q_cheese.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 맵 밖인 경우
            if (nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1)
                continue;

            // 방문한 적이 있는 경우
            if (cheese_visit[nx][ny] != 0)
                continue;

            // 외부 공기와 접촉한 경우
            if (map[nx][ny] == 2)
                contact_air++;

            // output();
        }

        // 두면 이상 외부 공기와 접촉한 경우
        if (contact_air >= 2)
            q_melting_cheese.push({x, y});

        // 이번에 안녹는 치즈
        else
            q_next_cheese.push({x, y});
    }

    // 녹을 치즈들 녹이기
    while (!q_melting_cheese.empty())
    {
        int x = q_melting_cheese.front().first;
        int y = q_melting_cheese.front().second;

        map[x][y] = 0;
        melt_count++;
        q_melting_cheese.pop();
    }

    // cout << melt_count << "\n";
}

// 모두 녹은지 확인(녹은 치즈 수 == 처음 치즈 수)
bool check_all_melt()
{
    if (melt_count == origin_cheese_count)
        return 1;
    else
        return 0;
}

// 외부 공기들로 bfs
void find_outside_air()
{
    memset(air_visit, 0, sizeof(air_visit));
    q_air = queue<pair<int, int>>();

    q_air.push({0, 0});
    map[0][0] = 2;
    air_visit[0][0]++;

    while (!q_air.empty())
    {
        int x = q_air.front().first;
        int y = q_air.front().second;
        q_air.pop();

        //if (x == N - 1 && y == M - 1)
        //   return;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 맵 밖인 경우
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            // 방문한 적이 있는 경우
            if (air_visit[nx][ny] != 0)
                continue;

            // 치즈에 막혀서 못가는 경우 제외
            if (map[nx][ny] != 1)
            {
                map[nx][ny] = 2;

                q_air.push({nx, ny});
                air_visit[nx][ny]++;
            }
        }
    }
}

int main(void)
{
    memset(map, 0, sizeof(map));
    input();
    year = 0;
    melt_count = 0;
    if (q_cheese.empty())
    {
        cout << "0";
        return 0;
    }

    melt_cheese();
}