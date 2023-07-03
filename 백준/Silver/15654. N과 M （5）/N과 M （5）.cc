#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v_N;
vector<int> v;
int num[10001];

void solve(int index)
{
    if (index == M)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < v_N.size(); i++)
    {
        if (num[v_N[i]] == 1)
            continue;
        v.push_back(v_N[i]);
        num[v_N[i]] = 1;
        solve(index + 1);
        v.pop_back();
        num[v_N[i]] = 0;
    }
}

int main(void)
{
    cin >> N >> M;

    int n = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        v_N.push_back(n);
    }
    sort(v_N.begin(), v_N.end());

    solve(0);
}