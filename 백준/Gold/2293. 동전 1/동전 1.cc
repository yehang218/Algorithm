#include <iostream>

using namespace std;

int n, k;
int dp[10001];
int coin[101];

int solve()
{
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = coin[i]; j <= k; j++)
        {
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }

    return dp[k];
}

int main(void)
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }

    cout << solve();
}