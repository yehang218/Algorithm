// 문제 분석
/*
 피보나치 수 5에 비해 n이 조금 더 커진 dp문제
 90까지기때문에 오버플로우를 조심해야한다..
*/

#include <iostream>

using namespace std;

int n;
long long dp[91];

int main(void)
{
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];
}