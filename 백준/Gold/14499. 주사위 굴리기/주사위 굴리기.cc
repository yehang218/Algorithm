// 굴림
// 바닥이 0 -> 주사위의 바닥면이 칸에 복사
// 바닥 0 x -> 바닥 수 주사위의 바닥면에 복사, 바닥은 0으로 바뀜

// 이동할때마다 상단에 쓰여 있는 값 구하기
// 지도 바깥으로는 이동 X

#include <iostream>
#include <vector>

using namespace std;

int N, M; // 지도의 크기
int map[21][21];
int x, y;        // 주사위를 처음 놓은 곳의 좌표
int K;           // 명령의 개수
int order[1001]; // 명령이 담길 배열

// 처음 주사위 모든 면은 0
vector<int> dice(7);

// 동→ 서← 북↑ 남↓
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void output()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "dice : " << dice[1];
}

void input()
{
    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < K; i++)
    {
        cin >> order[i];
    }
}

// 동쪽(1), 서쪽(2), 북쪽(3), 남쪽(4)
void roll_dice(int num)
{
    if (num == 1)
    { // 동쪽일경우
        dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
    }
    else if (num == 2)
    { // 서쪽일 경우
        dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
    }
    else if (num == 3)
    { // 북쪽일 경우
        dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
    }
    else if (num == 4)
    { // 남족일 경우
        dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
    }
}

void solve()
{
    for (int i = 0; i < K; i++)
    {
        int nx = x + dx[order[i] - 1];
        int ny = y + dy[order[i] - 1];

        // cout << "{" << nx << "," << ny << "}" << "\n";

        // 범위 밖이면 해당 명령 무시
        if (nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1)
            continue;

        // 주사위 굴리기
        roll_dice(order[i]);
        cout << dice[1] << "\n";

        // 해당 위치로 처음 좌표 바꾸기
        x = nx;
        y = ny;

        // 바닥이 0 -> 주사위의 바닥면이 칸에 복사
        if (map[nx][ny] == 0)
        {
            map[nx][ny] = dice[6];
        }

        // 바닥 0 x -> 바닥 수 주사위의 바닥면에 복사, 바닥은 0으로 바뀜
        else if (map[nx][ny] != 0)
        {
            dice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }
    }

    // output();
}

int main(void)
{
    input();
    solve();
}