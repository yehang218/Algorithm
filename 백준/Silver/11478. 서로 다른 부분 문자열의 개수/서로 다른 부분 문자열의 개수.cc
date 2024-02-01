#include <iostream>
#include <string>
#include <map>

using namespace std;

string S; // 입력받을 문자열
map<string, int> m;

int solve()
{
    string str = "";
    for (int i = 0; i < S.length(); i++)
    {
        for (int j = 1; j <= S.length(); j++)
        {
            str = S.substr(i, j);
            m.insert({str, 0});
            if (str.size() < j)
                break;
        }
    }

    return m.size();
}

int main(void)
{
    cin >> S;
    cout << solve();
}