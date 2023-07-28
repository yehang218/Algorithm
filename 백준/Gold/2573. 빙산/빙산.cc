// 1. 동시에 녹아야하는데 순서대로 녹게 되어서 내 왼쪽 친구가 0이 된 상태라면..?
// -> visit 체크로 해결
// 하지만 매년 달라져야 하니까 매년 visit 초기화
// 2. 그럼 총 몇년 할지는 어떻게 판단하지..? -> 그런거 없이 그냥 나올때까지 while문 돌리기
// 3. 빙산이 두 덩어리로 분리된건 어떻게 판단하지? -> bfs를 하고나서의 빙산을 가지고 이어져있는 빙산의 수 찾기. 이 수가 남아있는 빙산의 수와 같지 않으면 분리된거
// 4. 모두 녹은건 어떻게 판단하징 -> 녹은 빙산 개수랑 처음 빙산 개수랑 같으면..?

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N; // 행의 개수
int M; // 열의 개수

vector<int> map[301];
queue<pair<int, int>> q;
queue<pair<int, int>> copy_q;
queue<pair<int, int>> check_devide_q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool visit[301][301];

int year;
int melt_iceburg = 0;
int origin_iceburg = 0;

void output();
void bfs();
bool devide_iceberg();
bool melting_all();

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int m;
            cin >> m;
            map[i].push_back(m);
            if (m != 0)
            {
                q.push({i, j});
                origin_iceburg = q.size();
            }
        }
    }
}

void next_year()
{
    while (1)
    {
        bfs();
        year++;

        check_devide_q = queue<pair<int, int>>();
        if (!copy_q.empty())
            check_devide_q.push(copy_q.front());
        else
        { // 첫 경우에 모두 녹은 경우도 0 리턴
            cout << "0"
                 << "\n";
            return;
        }
        // 나눠졌다면
        if (devide_iceberg())
        {
            cout << year << "\n";
            return;
        }
        // 다 녹을때까지 분리되지 않으면
        else if (melting_all())
        {
            cout << "0"
                 << "\n";
            return;
        }

        q = copy_q;
        copy_q = queue<pair<int, int>>(); // q2 초기화
    }
}

void bfs()
{
    memset(visit, 0, sizeof(visit));
    melt_iceburg = 0;

    while (!q.empty())
    {
        int x_iceberg = q.front().first;
        int y_iceberg = q.front().second;
        q.pop();
        visit[x_iceberg][y_iceberg] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx_iceberg = x_iceberg + dx[i];
            int ny_iceberg = y_iceberg + dy[i];

            if (nx_iceberg < 0 || ny_iceberg < 0 || nx_iceberg >= N || ny_iceberg >= M)
                continue;
            if (map[nx_iceberg][ny_iceberg] == 0 && !visit[nx_iceberg][ny_iceberg])
            {
                if (map[x_iceberg][y_iceberg] > 0)
                {
                    map[x_iceberg][y_iceberg]--;
                }
            }
        }
        if (map[x_iceberg][y_iceberg] > 0)
            copy_q.push({x_iceberg, y_iceberg});
        if (map[x_iceberg][y_iceberg] == 0)
            melt_iceburg++;
    }
    // cout << melt_iceburg << " \n";
}

// 이어져있는 빙산의 개수 != 남아있는 빙산의 수 => 분리됨
bool devide_iceberg()
{
    int result = 0;
    memset(visit, 0, sizeof(visit));

    while (!check_devide_q.empty())
    {
        // output();
        int x_iceberg = check_devide_q.front().first;
        int y_iceberg = check_devide_q.front().second;
        check_devide_q.pop();
        visit[x_iceberg][y_iceberg] = true;
        result++;

        for (int i = 0; i < 4; i++)
        {
            int nx_iceberg = x_iceberg + dx[i];
            int ny_iceberg = y_iceberg + dy[i];

            if (nx_iceberg < 0 || ny_iceberg < 0 || nx_iceberg >= N || ny_iceberg >= M)
                continue;
            if (map[nx_iceberg][ny_iceberg] != 0 && !visit[nx_iceberg][ny_iceberg])
            {
                if (map[x_iceberg][y_iceberg] > 0)
                {
                    visit[nx_iceberg][ny_iceberg] = true;
                    check_devide_q.push({nx_iceberg, ny_iceberg});
                }
            }
        }
    }
    // cout << result << "\n";
    if (result != copy_q.size())
        return true;
    else
        return false;
}

// 녹은 빙산 개수랑 처음 빙산 개수랑 같으면..?
bool melting_all()
{
    // cout << "m " << melt_iceburg << " o " << origin_iceburg <<"\n";
    if (melt_iceburg == origin_iceburg)
        return true;
    else
        return false;
}

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

int main(void)
{
    input();
    next_year();
}