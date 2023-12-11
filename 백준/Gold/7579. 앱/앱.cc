#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int memory[101];
int costs[101];
int DP[101][10001];

int solve()
{
    int sum = 0;
    int result = 987654321;
    // 입력받은 총 코스트의 합 구하기
    for (int i = 1; i <= N; i++)
    {
        sum = sum + costs[i];
    }

    for (int index = 1; index <= N; index++)
    {
        for (int cost = 0; cost <= sum; cost++)
        {
            if (cost < costs[index])
            {
                DP[index][cost] = DP[index - 1][cost];
            }
            else
            {
                DP[index][cost] = max(DP[index - 1][cost - costs[index]] + memory[index], DP[index - 1][cost]);
            }

            if (DP[index][cost] >= M)
                result = min(result, cost);
        }
    }

    return result;
}

int main(void)
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> memory[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> costs[i];
    }

    cout << solve();
}