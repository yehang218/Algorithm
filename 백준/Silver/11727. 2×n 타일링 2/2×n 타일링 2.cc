#include <iostream>

using namespace std;

int DP[1001];

int solve(int n)
{
    DP[0] = 1;
    DP[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        DP[i] = ((DP[i - 2] * 2) + DP[i - 1]) % 10007;
    }

    return DP[n];
}

int main(void)
{
    int n;

    cin >> n;
    cout << solve(n);
}