#include <iostream>
#include <map>

using namespace std;

int N, M;
map<string, int> m;

void solve()
{
    int answer = 0;
    string str;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        m[str]++;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> str;
        if (m[str])
            answer++;
    }

    cout << answer;
}

int main(void)
{
    solve();
}