#include <iostream>
#include <bitset>

using namespace std;

int X;

void input()
{
    cin >> X;
}

int solve()
{
    int result = 0;
    bitset<7> stick(X);

    string str_stick = stick.to_string();

    for (int i = 0; i < str_stick.length(); i++)
    {
        if (str_stick[i] == '1')
            result++;
    }
    return result;
}

int main(void)
{
    input();
    cout << solve();
}