// 1) 거리가 가까운 물고기 판단은 어떻게하징 -> 시작 위치 바꿔주면서 bfs()쓰기
// 2) 왼쪽 위부터 먹는건 어떻게하징..?
// 좌표를 상좌우하로 하면되나..
// 이러면 같은 높이가 더 높아도 오른쪽이라서 먼저하는 경우가 생김
//        5
//    6  1  7
// 8  2  0  3  12
//    9  4  10
//       11
// -> 먹을 수 잇는 물고기 vector에 담아서 사이즈가 같으면 상단 위부터 / 다르면 작은 애들부터 0으로 만들어주고 상어 위치를 그 자리로
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct node
{
    int x;
    int y;
    int time;
} node;

int N;           // 공간의 크기
int map[21][21]; // 공간의 상태
queue<pair<int, int>> q;
int visit[21][21];

int start_x;
int start_y;

// x가 세로 y가 가로인 상태
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int shark_size = 2;    // 상어 사이즈
int eat_fish_size = 0; // 사이즈 체크 용 먹은 물고기 개수
int eat_fish_time = 0; // 물고기 먹는데 걸린 시간

bool cmp(node n1, node n2)
{
    if (n1.time == n2.time)
    {
        // 높이가 같으면
        if (n1.x == n2.x)
        {
            // 왼쪽부터
            return n1.y < n2.y;
        }
        return n1.x < n2.x;
    }
    return n1.time < n2.time;
}

// 테스트용 맵 출력문
void output()
{
    cout << "\n";
    cout << "\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
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
            if (map[i][j] == 9)
            {
                start_x = i;
                start_y = j;
                map[i][j] = 0;
            }
        }
    }
}

int bfs()
{
    memset(visit, 0, sizeof(visit));
    q.push({start_x, start_y});
    visit[start_x][start_y]++;

    vector<node> v;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 밖이면 탐색X
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;

            // 이미 방문했으면 탐색X
            if (visit[nx][ny] != 0)
                continue;

            // 큰 물고기라서 지나갈 수 없는 경우
            if (map[nx][ny] > shark_size)
                continue;

            // 먹을 수 있는 물고기
            if (map[nx][ny] != 0 && map[nx][ny] < shark_size)
            {
                // 먹을 수 있는 물고기 벡터에 넣기
                node n;
                n.x = nx;
                n.y = ny;
                n.time = visit[x][y] + 1;
                v.push_back(n);
            }

            visit[nx][ny] = visit[x][y] + 1;
            q.push({nx, ny});
        }
    }

    if (!v.empty())
    {
        sort(v.begin(), v.end(), cmp);
        node n = v[0];

        start_x = n.x;
        start_y = n.y;
        eat_fish_time = eat_fish_time + n.time - 1; // 시작 길이 1부터 했으므로
        return 1;
    }
    // 비어있으면 먹을 수 있는 물고기가 없다는 뜻이므로
    else
        return 0;

    // cout << eat_fish_time << "\n";
}

int main(void)
{
    input();

    while (1)
    {
        int b = bfs();
        // output();
        if (b == 1) // 먹었으면
        {
            eat_fish_size++;
            map[start_x][start_y] = 0; // 먹은 물고기 빈칸으로 바꾸기
            if (eat_fish_size == shark_size)
            {
                // 상어 사이즈 증가
                shark_size++;
                eat_fish_size = 0;
            }
            // cout << shark_size << "\n";
        }
        else
        { // 먹을 수 있는게 없음
            break;
        }
    }
    cout << eat_fish_time;
}