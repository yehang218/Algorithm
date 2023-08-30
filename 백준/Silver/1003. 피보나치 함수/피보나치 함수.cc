#include <iostream>

using namespace std;

int T;
int N;
int result_0[41] = {
    1,
    0,
};
int result_1[41] = {
    0,
    1,
};

void solve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        result_0[i] = result_0[i - 1] + result_0[i - 2];
        result_1[i] = result_1[i - 1] + result_1[i - 2];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        solve(N);

        cout << result_0[N] << " " << result_1[N] << "\n";
    }
}