#include <iostream>

using namespace std;

int n; // 1 <= n <= 10

char origin_map[11][11]; // . : 지뢰 X / * : 지뢰 o
char open_map[11][11];   // x : 이미 열린 칸 / . : 열리지 않은 칸

bool is_open_mine = false; // 지뢰 있는 칸이 열렸다면 지뢰 있는 모든 칸 * 표시

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> origin_map[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> open_map[i][j];

            // 열려있는 맵인데 지뢰가 있는 곳이라면
            if (open_map[i][j] == 'x' && origin_map[i][j] == '*')
                is_open_mine = true;
        }
    }
}

void set_map(int x, int y)
{
    int around_mine = 0;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 맵 범위 밖이라면
        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;

        if (origin_map[nx][ny] == '*')
            around_mine++;
    }

    open_map[x][y] = around_mine + '0';
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (is_open_mine == true && origin_map[i][j] == '*')
                open_map[i][j] = '*';
            if (open_map[i][j] == 'x')
            {
                set_map(i, j);
            }
        }
    }
}

void output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << open_map[i][j];
        }
        cout << "\n";
    }
}

int main(void)
{
    input();
    solve();
    output();
}