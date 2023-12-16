#include <iostream>

using namespace std;

int N;
int DP[101][10];

int solve()
{
    for (int i = 1; i < 10; i++)
    {
        DP[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
            {
                DP[i][j] = DP[i - 1][j + 1];
            }
            else if (j == 9)
            {
                DP[i][j] = DP[i - 1][j - 1];
            }
            else
            {
                DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j + 1];
            }

            DP[i][j] = DP[i][j] % 1000000000;
        }
    }

    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        result = (result + DP[N][i]) % 1000000000;
    }
    return result;
}

int main(void)
{
    cin >> N;

    cout << solve();
}