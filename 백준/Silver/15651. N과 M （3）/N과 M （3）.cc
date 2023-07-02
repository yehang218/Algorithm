#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void solve(int index)
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

    for (int i = 1; i <= N; i++)
    {
        v.push_back(i);
        solve(index + 1);
        v.pop_back();
    }
}

int main(void)
{
    cin >> N >> M;
    solve(0);
}