#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[1001];
int answer[1001];

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

void solve()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                answer[i] = max(answer[j] + 1, answer[i]);
        }
    }
}

int main(void)
{
    input();
    solve();

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        result = max(result, answer[i]);
    }
    cout << result + 1;
}