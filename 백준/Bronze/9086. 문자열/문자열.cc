#include <iostream>
#include <string>

using namespace std;

string str[1001];

void solve(int N)
{
    for (int i = 0; i < N; i++)
    {
        cin >> str[i];
        int len = str[i].length();
        cout << str[i][0] << str[i][len - 1] << "\n";
    }
}

int main(void)
{
    int N;
    cin >> N;

    solve(N);
}