#include <iostream>

using namespace std;

int N, M;
int arr[100001];
int sum[100001];

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, result;
    cin >> N >> M;

    cin >> arr[1];
    sum[1] = arr[1];
    for (int i = 2; i <= N; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << "\n";
    }
}

int main(void)
{
    solve();
}