#include <iostream>

using namespace std;

int dp[12];

int solve(int n)
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main(void)
{
    int T;
    int n;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        cout << solve(n) << "\n";
    }
}