#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void solve(int index, int now)
{
    if (index == M)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = now; i <= N; i++)
    {
        v.push_back(i);
        solve(index + 1, i + 1);
        v.pop_back();
    }
}

int main(void)
{
    cin >> N >> M;

    if (M == 1)
    {
        for (int i = 1; i <= N; i++)
        {
            cout << i << "\n";
        }
        return 0;
    }

    solve(0, 1);
}