#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T;
string answer = "";

string solve(int k, vector<string> v_str);
bool find_palindrome(string str);

void input()
{
    int k = 0;
    string str1 = "";

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        vector<string> v_str;

        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> str1;
            v_str.push_back(str1);
        }

        cout << solve(k, v_str) << "\n";
    }
}

string solve(int k, vector<string> v_str)
{
    string str = "";
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i == j) continue;
            str = v_str[i] + v_str[j];
            if (find_palindrome(str)) return str;
        }
    }

    return "0";
}

bool find_palindrome(string str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - i - 1]) return false;
    }

    return true;
}

int main(void)
{
    input();
}