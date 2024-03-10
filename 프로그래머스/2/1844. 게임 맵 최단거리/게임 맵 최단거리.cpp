#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q;
int check[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(vector<vector<int>> maps, int sx, int sy)
{
    int maxRow = maps.size();
    int maxCol = maps[0].size();

    q.push({sx, sy});
    check[sx][sy]++;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= maxRow || ny >= maxCol)
                continue;
            if (check[nx][ny] != 0)
                continue;
            if (maps[nx][ny] == 0)
                continue;

            q.push({nx, ny});
            check[nx][ny] = check[x][y] + 1;
        }
    }

    return check[maxRow - 1][maxCol - 1] != 0 ? check[maxRow - 1][maxCol - 1] : -1;
}

int solution(vector<vector<int>> maps)
{
    return bfs(maps, 0, 0);
}