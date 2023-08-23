// 자료 구조가 중요한 문제 -> 뭘 써야할까?? 앞뒤로 증가 감소 하니까 deque?
// 사과를 먹으면 뱀 길이 증가
// 벽이나 자기 자신의 몸과 부딪히면 게임 끝
// (0, 0)에서 시작 뱀 길이 1로 시작

// 1. 방향 전환 필요한지 확인 -> 이동
// 2. 그 칸이 뭔지 확인
#include <iostream>
#include <deque>

using namespace std;

int N; // 보드 크기
int K; // 사과 개수
int L; // 뱀 방향 변환 횟수
int map[105][105];
int twist_snake[10001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dir = 0;

typedef struct node
{
    int x;
    int y;
} node;

deque<node> dq;
void twist_head(int dir_i, int dir_c);
void input()
{
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1; // 사과 위치 저장
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        int sec;
        char dir;
        cin >> sec >> dir;
        if (dir == 'D')
            twist_snake[sec] = 1;
        else if (dir == 'L')
            twist_snake[sec] = 2;
    }

    // for(int i = 1; i< N+1; i++)
    // {
    //     for(int j = 1; j<N+1; j++)
    //         cout << map[i][j] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
}

int move_snake()
{
    // 오 : 0, 아 : 1, 왼 : 2, 위 : 3

    // 총 움직인 횟수
    int count = 0;
    dq.push_front({1, 1});

    while (true)
    {
        count++;

        // 이동
        // 머리의 위치
        int nx = dq.front().x + dx[dir];
        int ny = dq.front().y + dy[dir];
        // cout << "x : " << nx << " y : " << ny <<"\n";
        dq.push_front({nx, ny});

        // 벽인지 확인
        if (nx < 1 || ny < 1 || nx > N || ny > N)
        {
            // cout << "wall\n";
            return count;
        }

        // 몸인지 확인
        if (map[ny][nx] == 2)
            return count;

        // cout << dq.size() << "\n";
        // for (int i = 0; i < dq.size(); i++)
        // {
        //     int x = dq.at(i).x;
        //     int y = dq.at(i).y;

        //     // 몸이라면 멈추기
        //     if (nx == x && ny == y)
        //     {
        //         // cout << "body\n";
        //         return count;
        //     }
        // }

        // 사과 먹고 꼬리 빼기는 넘어가기
        if (map[ny][nx] == 1)
        {
            map[ny][nx] == 2;
        }
        // 사과가 아니라면 꼬리 빼기
        else
        {
            map[ny][nx] = 2;
            map[dq.back().y][dq.back().x] = 0;
            dq.pop_back();
        }

        // 방향 전환 필요한지 확인
        if (twist_snake[count] != 0)
        {
            twist_head(dir, twist_snake[count]);
        }
    }
}

// 방향 전환
void twist_head(int dir_i, int dir_c)
{
    if (dir_i == 0)
    {
        if (dir_c == 1)
            dir = 1;
        else if (dir_c == 2)
            dir = 3;
    }

    else if (dir_i == 1)
    {
        if (dir_c == 1)
            dir = 2;
        else if (dir_c == 2)
            dir = 0;
    }

    else if (dir_i == 2)
    {
        if (dir_c == 1)
            dir = 3;
        if (dir_c == 2)
            dir = 1;
    }

    else if (dir_i == 3)
    {
        if (dir_c == 1)
            dir = 0;
        else if (dir_c == 2)
            dir = 2;
    }
}

int main(void)
{
    input();
    cout << move_snake();
}