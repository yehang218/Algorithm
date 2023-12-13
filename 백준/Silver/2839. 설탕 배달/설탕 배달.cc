#include <iostream>
#include <cstring>

using namespace std;

int N; // 배달할 설탕 무게

int solve()
{
    int result = 0;

    while (N >= 0)
    {
        if (N % 5 == 0)
        {
            result += N / 5;
            return result;
        }
        result++;
        N = N - 3;
    }

    return -1;
}

int main(void)
{
    cin >> N;

    cout << solve();
}