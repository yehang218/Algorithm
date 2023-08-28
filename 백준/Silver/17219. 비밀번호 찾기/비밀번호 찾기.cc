#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
    int N; // 저장된 사이트 주소의 수
    int M; // 비밀번호를 찾으려는 사이트 주소의 수

    map<string, string> site_password;

    cin >> N >> M;

    string site, password;
    for (int i = 0; i < N; i++)
    {
        cin >> site >> password;
        site_password[site] = password;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> site;
        cout << site_password[site] << "\n";
    }
}