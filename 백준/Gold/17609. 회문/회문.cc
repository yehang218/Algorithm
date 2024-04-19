// 문제 분석
/*
 앞 뒤 방향으로 볼 때 같은 순서 -> 회문 0
 회문 X → 한 문자 삭제했을 때, 회문 가능 -> 유사 회문 1
        ↳ 그럼에도 안되면 -> 일반 문자열 2

 0. 모두 삭제하지 말고, 회문이 안되는 원인만 제거해보기!
 1. 처음 확인할 때, 원인 인덱스를 넣어서
 2. 유사회문 검사할 때, 삭제하고 검사해보기!
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T; // 문자열의 개수
vector<string> v_words;
vector<int> v_check[31];

// 회문 검사
bool check_is_palindrome(bool is_frist, int index, string str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        if (str[i] != str[str.length() - i - 1])
        {
            // 유사 회문 검사할 때는 넣지 않기
            if (is_frist)
            {
                v_check[index].push_back(i);
                v_check[index].push_back(str.length() - i - 1);
            }

            return false;
        }
    }
    return true;
}

// 유사 회문 검사
bool check_is_pseudo_palindrome(int index, string str)
{
    while (!v_check[index].empty())
    {
        int erase_index = v_check[index].back();
        v_check[index].pop_back();
        string temp1 = str;

        temp1.erase(temp1.begin() + erase_index);

        if (check_is_palindrome(false, index, temp1)) return true;
    }

    return false;
}

void input()
{
    string str = "";

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> str;

        if (check_is_palindrome(true, i, str)) cout << "0";
        else cout << (check_is_pseudo_palindrome(i, str) ? "1" : "2");
        cout << "\n";
    }
}

int main(void)
{
    input();
}