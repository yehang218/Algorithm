#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m; // 세로 크기, 가로 크기

vector<int> v; // 연결 확인
int map[501][501];
bool visit[501][501]; // 방문 확인 배열
int countPainting;    // 그림 개수

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// 맵 정보 입력 받기
void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
}

int bfs(int i, int j)
{
    int result = 0;
    queue<pair<int, int>> q;

    q.push({i, j});
    visit[i][j] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visit[nx][ny] == true)
                continue;
            if (map[nx][ny] == 0)
                continue;

            visit[nx][ny] = true;
            q.push({nx, ny});
            result++;
        }
    }

    return result + 1;
}

// (0, 0)부터 bfs() 시작
int checkMap()
{
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && visit[i][j] == false) // 그림 범위이고 확인안한 곳이라면
            {
                countPainting++;
                maxArea = max(maxArea, bfs(i, j));
            }
        }
    }

    return maxArea;
}

int main()
{
    input();
    int result = checkMap();
    cout << countPainting << "\n"
         << result;
}
