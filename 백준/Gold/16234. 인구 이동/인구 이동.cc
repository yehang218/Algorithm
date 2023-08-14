// 1. 국경선 열기(L이상 R이하)
// 2. 인구 이동 시작
// 3. 연합 체크는 어떻게 하징
// 3.1) 연합 확인(모든 위치 BFS로 확인)
// 3.2) 표시한 연합끼리 같은 연합
// 4. 연합 해체, 국경선 닫기
// 5. 총 며칠동안 발생?

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, L, R;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int map[51][51];
int visit[51][51];
int same_visit[51][51];

bool is_group = false;

int group_people[2600];

typedef struct node
{
    int x;
    int y;
} node;

queue<node> q;
queue<node> group_q;

void bfs(int sx, int sy);
void start_all();

void output()
{
    cout << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void input()
{
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
}

void start_all()
{
    int day = 0;
    while (true)
    {
        is_group = false;
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // 이미 확인했다면 다른거로
                if (visit[i][j] != 0)
                    continue;
                bfs(i, j);
            }
        }

        // 그룹이 없었으면
        if (!is_group)
        {
            cout << day;
            return;
        }
        day++;
    }
}

// 같은 연합 체크
void bfs(int sx, int sy)
{
    memset(same_visit, 0, sizeof(same_visit));
    int group_num = 0; // 같은 연합이 몇개인지
    int peole_num = 0; // 연합안에 사람이 몇명인지

    q.push({sx, sy});
    visit[sx][sy]++;
    same_visit[sx][sy]++;
    group_num++;
    peole_num = peole_num + map[sx][sy];

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int p = map[x][y];
        group_q.push({x, y});
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 밖이면 다음꺼 확인
            if (nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1)
                continue;

            // 이전에 확인했던거라면 다음꺼 확인
            if (visit[nx][ny] != 0)
                continue;

            int np = map[nx][ny];
            int cal_np = abs(p - np);
            if (cal_np >= L && cal_np <= R)
            {
                is_group = true;
                visit[nx][ny]++;
                same_visit[nx][ny]++;
                q.push({nx, ny});
                group_num++;
                peole_num = peole_num + np;
            }
        }
    }

    int check = 0;
    int cal_group = peole_num / group_num;
    /*
    // 인구 이동
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 이번에 방문한 친구라면
            if (same_visit[i][j] != 0)
            {
                map[i][j] = cal_group;
                check++;
            }
            if (check == group_num)
                return;
        }
    }
    */

    while (!group_q.empty())
    {
        int x = group_q.front().x;
        int y = group_q.front().y;
        group_q.pop();

        map[x][y] = cal_group;
    }
}

int main(void)
{
    input();
    // output();
    start_all();
}