// 1인 곳 queue에 저장
// (바꾸면서 숫자 세기 -> 벡터에 저장)
// 최대로 ++된 수 -> 총 단지 수

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int map[26][26];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int visit[26][26];
int count_house[700]; // 각 단지의 집 수 저장 배열
int cnt;             // 마을 단지 인덱스

queue<pair<int, int>> q;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }
}

void output()
{
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

void bfs(int start, int end)
{
    q.push({start, end});
    visit[start][end]++;
    count_house[cnt]++;
    map[start][end] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (visit[nx][ny] != 0)
                continue;

            if (map[nx][ny] == 1)
            {
                q.push({nx, ny});
                visit[nx][ny]++;
                count_house[cnt]++;
                map[nx][ny] = 0;
            }
        }
    }
    // output();
    cnt++;
}

int main(void)
{
    input();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1)
                bfs(i, j);
        }
    }
    cout << cnt << "\n";
    sort(count_house, count_house + cnt);
    for (int i = 0; i < cnt; i++)
    {
        cout << count_house[i] << "\n";
    }
}