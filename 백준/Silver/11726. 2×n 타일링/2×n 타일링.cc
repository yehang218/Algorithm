#include <iostream>

using namespace std;

int solve(int n)
{
    int arr[1001];

    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }

    return arr[n];
}

int main(void)
{
    int n;
    cin >> n;

    int ans = solve(n);
    cout << ans;

    return 0;
}