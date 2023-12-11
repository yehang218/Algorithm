#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int w[101];
int v[101];
int DP[101][100001];

int solve()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j < w[i])
            {
                DP[i][j] = DP[i - 1][j];
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    return DP[N][K];
}

int main(void)
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> w[i] >> v[i];
    }

    cout << solve();
}