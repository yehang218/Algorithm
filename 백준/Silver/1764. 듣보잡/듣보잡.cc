#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 듣 X
int M; // 보 X

void solve()
{
    map<string, int> name;
    vector<string> result;
    int count = 0;
    string str;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> str;
        name[str] = i;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> str;
        if (name[str] != 0)
        {
            result.push_back(str);
            count++;
        }
    }

    cout << count << "\n";
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}

int main(void)
{
    solve();
}