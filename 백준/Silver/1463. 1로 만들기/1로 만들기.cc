// 3으로 나누어 떨어지면 3으로 나눔
// 2로 나누어 떨어지면 2로 나눔
// -1

// 배열에 지금까지의 횟수 담기

#include <iostream>

using namespace std;

int count[10000001];

void solve(int N)
{
    count[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        count[i] = count[i - 1] + 1;
        if (i % 3 == 0)
            count[i] = min(count[i], count[i / 3] + 1);
        if (i % 2 == 0)
            count[i] = min(count[i], count[i / 2] + 1);
    }

    cout << count[N];
}

int main(void)
{
    int N;
    cin >> N;
    solve(N);
}