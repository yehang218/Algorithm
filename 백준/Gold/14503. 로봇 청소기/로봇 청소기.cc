#include <iostream>

using namespace std;

int N, M; // 방의 크기
int map[51][51];

// 북, 동, 남, 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 빈칸이 있는 경우 d 리턴 / 없는 경우 -1 리턴
int check_around(int sx, int sy, int d)
{
    // 주변 4칸 확인
    for (int i = 0; i < 4; i++)
    {
        if (d != 0)
            d = d - 1;
        else if (d == 0)
            d = 3;

        int nx = sx + dx[d];
        int ny = sy + dy[d];

        // 맵 범위 넘어가면 다음 칸 확인
        if (nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1)
            continue;

        // 빈칸이 있는 경우
        if (map[nx][ny] == 0)
        {
            return d;
        }
    }

    // 빈칸이 없는 경우
    return -1;
}

int solve(int sx, int sy, int d)
{
    int result = 0;
    int x = sx;
    int y = sy;

    while (1)
    {
        // cout << "x" <<  x << " y" << y << "\n";
        //  현재 칸 청소 X -> 현재 칸 청소
        if (map[x][y] == 0)
        {
            map[x][y] = 2;
            result++; // 청소하는 칸의 개수 카운트
        }

        int check_around_num = check_around(x, y, d);

        // 빈칸이 있는 경우
        if (check_around_num != -1)
        {
            // 회전한 방향 업데이트
            d = check_around_num;
            // 한칸 전진
            x = x + dx[d];
            y = y + dy[d];
        }

        // 빈칸이 없는 경우
        else if (check_around_num == -1)
        {
            int nd = 0;
            // 보는 방향에 따라 후진
            if (d == 0)
                nd = 2;
            else if (d == 1)
                nd = 3;
            else if (d == 2)
                nd = 0;
            else if (d == 3)
                nd = 1;

            // 한칸 후진
            x = dx[nd] + x;
            y = dy[nd] + y;

            if (x < 0 || y < 0 || x > N - 1 || y > M - 1)
                return -1; // 오류인 경우

            // 후진하려고 했는데 벽인 경우 작동 정지
            if (map[x][y] == 1)
                return result;
        }
    }
}

int main(void)
{
    int r, c; // 로봇 청소기가 있는 칸의 좌표
    int d;    // 로봇 청소기가 바라보는 방향

    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    cout << solve(r, c, d);
}