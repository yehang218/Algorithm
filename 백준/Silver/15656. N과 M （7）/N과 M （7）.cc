#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
vector<int> v_N;

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
        v.push_back(v_N[i]);
        solve(index + 1);
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
    solve(0);
}