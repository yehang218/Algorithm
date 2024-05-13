// 문제 분석
/*
    dp[5]부터 dp[0] + dp[4];
    dp[6] = dp[1] + dp[5];
    ...
    이런식으로 진행되므로
    점화식 = dp[i-5] + dp[i-1]

    이때, T만큼 출력해야 하는데, 매번 DP를 계속 구하는건 낭비이므로 한번에 100까지 구해두고
    입력된 수만 출력하기
*/

#define MAX 100

#include <iostream>
using namespace std;

int T;
long long dp[101];

void input()
{
    int num = 0;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> num;
        cout << dp[num] << "\n";
    }
}

void setDP()
{
    dp[0] = 0;
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = 2;

    for (int i = 5; i <= MAX; i++)
    {
        dp[i] = dp[i - 5] + dp[i - 1];
    }
}

int main(void)
{
    setDP();
    input();
}