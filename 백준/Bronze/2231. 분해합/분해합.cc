#include <iostream>

using namespace std;

int N;

int solve()
{
    int num = 0;
    int help_num = 0;

    for (int i = 0; i < N; i++)
    {
        num = i;
        help_num = i;
        while (help_num > 0)
        {
            num = num + (help_num % 10);
            help_num = help_num / 10;
        }

        if (num == N)
        {
            return i;
        }
    }

    return 0;
}

int main(void)
{
    cin >> N;
    cout << solve();
}