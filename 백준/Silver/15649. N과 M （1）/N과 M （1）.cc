#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int check[9];
int N;
int M;

void solve(int index)
{
    if (index == M)
    {
        for (int i = 0; i < index; i++)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (check[i] == 1)
            continue;
        v.push_back(i);
        check[i] = 1;
        solve(index + 1);
        v.pop_back();
        check[i] = 0;
    }
}

int main(void)
{
    cin >> N;
    cin >> M;

    if (M == 1)
    {
        for (int i = 1; i <= N; i++)
        {
            cout << i << '\n';
        }
        return 0;
    }

    solve(0);
}