// 문제 분석
/*
 dp 연습문제
*/

#include <iostream>

using namespace std;

int dp[21];

int main(void)
{
    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];
}