#include <iostream>

using namespace std;

int N;
char star[3072][6144];

void solve(int x, int y, int n)
{
    if (n == 3)
    {
        star[y][x] = '*';
        star[y + 1][x - 1] = '*';
        star[y + 1][x + 1] = '*';
        star[y + 2][x - 2] = '*';
        star[y + 2][x - 1] = '*';
        star[y + 2][x] = '*';
        star[y + 2][x + 1] = '*';
        star[y + 2][x + 2] = '*';
        return;
    }

    solve(x, y, n / 2);
    solve(x - n / 2, y + n / 2, n / 2);
    solve(x - n / 2 + n, y + n / 2, n / 2);
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N - 1; j++)
        {
            star[i][j] = ' ';
        }
    }
    solve(N - 1, 0, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N - 1; j++)
        {
            cout << star[i][j];
        }
        cout << "\n";
    }
}