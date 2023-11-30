#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> v_password;
vector<char> v_alphabet;
void solve(int index, int now)
{
    if (index == L)
    {
        int check_v = 0; // 모음 개수
        int check_c = 0; // 자음 개수
        for (int i = 0; i < v_password.size(); i++)
        {
            if (v_password[i] == 'a' || v_password[i] == 'e' || v_password[i] == 'i' || v_password[i] == 'o' || v_password[i] == 'u')
            {
                check_v++;
            }
            else
                check_c++;
        }

        if (check_v >= 1 && check_c >= 2)
        {
            for (int i = 0; i < v_password.size(); i++)
            {
                cout << v_password[i];
            }
            cout << "\n";
        }

        return;
    }

    for (int i = now; i < C; i++)
    {
        v_password.push_back(v_alphabet[i]);
        solve(index + 1, i + 1);
        v_password.pop_back();
    }
}

int main(void)
{
    char c;
    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        cin >> c;
        v_alphabet.push_back(c);
    }
    sort(v_alphabet.begin(), v_alphabet.end());
    solve(0, 0);
}