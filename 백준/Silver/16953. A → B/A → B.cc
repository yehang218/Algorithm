#include <iostream>
#include <queue>

using namespace std;

long long A, B;

void solve()
{
    queue<pair<long long, int>> q;
    cin >> A >> B;

    q.push({A, 1});

    while (!q.empty())
    {
        long long x = q.front().first;
        int count = q.front().second;
        q.pop();

        for (int i = 0; i < 2; i++)
        {
            long long nx;
            if (i == 0)
                nx = x * 2;
            else if (i == 1)
                nx = x * 10 + 1;
            if (nx > B)
                continue;
            q.push({nx, count + 1});
            if (nx == B)
            {
                cout << count + 1;
                return;
            }
        }
    }
    cout << "-1";
}

int main(void)
{
    solve();
}