#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, float> m_tree;

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    float count = .0f;

    while (getline(cin, str))
    {
        count++;
        m_tree[str]++;
    }

    cout << fixed;
    cout.precision(4);
    for (auto it = m_tree.begin(); it != m_tree.end(); it++)
    {
        cout << it->first << " " << (it->second / count) * 100 << "\n";
    }
}

int main(void)
{
    solve();
}