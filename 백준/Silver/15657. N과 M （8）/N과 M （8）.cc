#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v_N;
vector<int> v;

void solve(int index, int now)
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

    for (int i = now; i < v_N.size(); i++)
    {
        v.push_back(v_N[i]);
        solve(index + 1, i);
        v.pop_back();
    }
}

int main(void)
{
    int num = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v_N.push_back(num);
    }
    sort(v_N.begin(), v_N.end());
    solve(0, 0);
}