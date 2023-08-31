// 집은 앞뒤의 색과 같으면 안됨
#include <iostream>
#include <cstring>

using namespace std;

int N; // 집의 개수

int home[1001][3];

void solve()
{
    int cost[3];
    home[0][0] = 0;
    home[0][1] = 0;
    home[0][2] = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];

        // i번째 집을 빨강으로 칠하려면 전의 집이 파랑이거나 초록이어야함
        // 바로 이전 집의 누적 비용이 최소인거 선택
        home[i][0] = min(home[i - 1][1], home[i - 1][2]) + cost[0];
        home[i][1] = min(home[i - 1][0], home[i - 1][2]) + cost[1];
        home[i][2] = min(home[i - 1][0], home[i - 1][1]) + cost[2];
    }
    cout << min(home[N][0], min(home[N][1], home[N][2]));
}

int main(void)
{
    cin >> N;
    solve();
}