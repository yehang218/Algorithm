#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int N; // 도감에 수록되어 있는 포켓몬의 개수
int M; // 맞춰야하는 문제의 개수

map<string, int> m;
string arr_name[100001];

void input()
{
    string name;
    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> name;
        m[name] = i;
        arr_name[i] = name;
    }
}

void solve()
{
    string name;
    int num = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> name;
        if (name[0] >= 65 && name[0] <= 90)
        { // 포켓몬 이름인 경우(맨 첫글자 대문자)
            cout << m[name] << "\n";
        }
        else
        {
            num = stoi(name);
            cout << arr_name[num] << "\n";
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
}