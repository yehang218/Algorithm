// 하루마다 토마토 익히기
// 하루 끝나면 모두 익었는지 확인
// 모두 익었으면 출력
// 방향 : 위 아래 왼 오 앞 뒤

// 익은 토마토를 벡터에 저장해서
// 그 위치부터 주변 토마토 익힘
// 판단할때는 원래 배열을 새로 복사한 배열로 판단

#include <iostream>
#include <queue>

using namespace std;

int M, N; // 상자의 크기
int H;    // 높이

int box[101][101][101];

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

struct node
{
    int x;
    int y;
    int h;
};

queue<node> q_ripe_tomato; // 익은 토마토 담긴 큐
int visit[101][101][101] = {0};

int not_ripe_tomato;
int day = 0;

void input()
{
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                { // 익은 토마토라면
                    q_ripe_tomato.push({i, j, k});
                    visit[i][j][k]++;
                }
                else if (box[i][j][k] == 0)
                    not_ripe_tomato++;
            }
        }
    }
}

void bfs()
{
    while (!q_ripe_tomato.empty())
    {
        int q_size = q_ripe_tomato.size();

        for (int index = 0; index < q_size; index++)
        {
            int x = q_ripe_tomato.front().x;
            int y = q_ripe_tomato.front().y;
            int h = q_ripe_tomato.front().h;
            q_ripe_tomato.pop();

            // cout << x << " " << y << " " << h << " " << '\n';

            for (int i = 0; i < 6; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nh = h + dh[i];

                if (nx < 0 || ny < 0 || nh < 0)
                    continue;
                if (nx >= H || ny >= N || nh >= M)
                    continue;

                if (visit[nx][ny][nh] != 0)
                    continue;

                // 익지 않은 토마토라면
                if (box[nx][ny][nh] == 0)
                {
                    visit[nx][ny][nh] = visit[x][y][h] + 1;
                    not_ripe_tomato--;
                    q_ripe_tomato.push({nx, ny, nh});
                    // cout << not_ripe_tomato << " ";
                }
            }
        }
        day++;
        // cout << day << " ";
    }
}

void solve()
{
    bfs();
    if (not_ripe_tomato > 0) // 안익은 토마토가 있다면
    {
        cout << "-1";
        return;
    }

    cout << day - 1;
}

int main(void)
{
    input();

    // 이미 모든 토마토가 익었다면
    if (not_ripe_tomato == 0)
    {
        cout << "0";
    }
    else
    {
        solve();
    }
}