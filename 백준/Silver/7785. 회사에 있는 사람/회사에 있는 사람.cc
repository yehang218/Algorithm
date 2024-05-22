#include <iostream>
#include <map>

using namespace std;

int n; // 출입 기록 수 (2 <= n <= 10000000)
map<string, string, greater<string>> company_record;

void input()
{
    string name = "";
    string record = "";

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        cin >> record;

        company_record[name] = record;
    }
}

void solve()
{
    for (auto it = company_record.begin(); it != company_record.end(); it++)
    {
        if (it->second == "enter") cout << it->first << "\n";
    }
}

int main(void)
{
    input();
    solve();
}