#include <iostream>

using namespace std;

int N, M;
int cards[101];

void input()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> cards[i];
}

int solve()
{
    int sum = 0;
    int result = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                sum = cards[i] + cards[j] + cards[k];
                if (result < sum && sum <= M)
                    result = sum;
            }
        }
    }
    return result;
}

int main(void)
{
    int num = 0;

    input();
    cout << solve();
}