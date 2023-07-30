// 0. 입력 받을 때 띄어쓰기 없이 주어지던데 한글자씩 받아야함!! -> char써서 해결
// 1. 우선 다 부숴보고 제일 작은거 찾기.
// 근데 그러면 안부쉈을때가 더 작을땐 어떡하징..? 그 경우도 다 해봐야하나? 시간 초과 안나려나
// 시간초과 난다ㅏ.. 어떻게 해결하징!?!

// -> bsf를 한번만 쓴다(visit에 벽을 부쉈는지도 함께 저장해서)
// -> 1) 부순적 없고 벽이 있는 곳
// -> 2) 부순적 있고 벽이 없는 곳
// -> 3) 부순적 없고 벽도 없는 곳

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M; // 맵 크기

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int map[1001][1001];

typedef struct node
{
    int x;
    int y;
    int is_break;
} node;

queue<node> q;
int visit[1001][1001][2];
char c;

void bfs();

// 테스트용 맵 출력문
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
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            // 띄어쓰기 없이 한줄이 통으로 들어와서 숫자 한개씩 받으려고 char 선언
            cin >> c;
            map[i][j] = c - '0';
        }
    }

    // output();
}

void bfs()
{
    // (0, 0) ~ (N-1, M-1)와 같음
    q.push({0, 0, 0});
    visit[0][0][0]++; // 처음꺼 방문 처리 -> 벽 부순적 없으니까 0,0,0

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int break_wall = q.front().is_break;
        q.pop();

        // (0, 0) 부터 시작했으므로 (N-1, M-1)이 마지막
        if (x == N - 1 && y == M - 1)
        {
            cout << visit[x][y][break_wall];
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 맵 밖이면 탐색X
            if (nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1)
                continue;

            // 방문했던 곳이면 탐색X
            if (visit[nx][ny][break_wall] != 0)
                continue;

            // 부순적 없고 벽이 아니라면
            if (break_wall == 0 && map[nx][ny] == 0)
            {
                // 그냥 좌표 넣기
                q.push({nx, ny, 0});
                visit[nx][ny][0] = visit[x][y][0] + 1;
            }

            // 부순적 없고 벽이라면
            if (break_wall == 0 && map[nx][ny] == 1)
            {
                // 부수고 좌표 넣기
                q.push({nx, ny, 1});
                visit[nx][ny][1] = visit[x][y][0] + 1;
            }

            // 부순적 있고 벽이 아니라면
            if (break_wall == 1 && map[nx][ny] == 0)
            {
                // 그냥 좌표 넣기 + 전에 부순적 있긴 하니까 break_wall 그대로 유지
                q.push({nx, ny, 1});
                visit[nx][ny][1] = visit[x][y][1] + 1;
            }
        }
    }

    // 어떤 경우에도 N-1, M-1에 도달하지 못했다면 불가능한 경우이므로 -1 출력
    cout << "-1";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    bfs();
}