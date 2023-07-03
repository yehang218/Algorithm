#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v_N;
vector<int> v;
int num[10001];

void solve(int index, int now)
{
    if (M == index)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = now; i < v_N.size(); i++)
    {
        if (num[v_N[i]] == 1)
            continue;

        v.push_back(v_N[i]);
        num[v_N[i]] = 1;
        solve(index + 1, i + 1);
        v.pop_back();
        num[v_N[i]] = 0;
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
    solve(0, 0); // v_N의 index라서 now도 0부터 시작
}