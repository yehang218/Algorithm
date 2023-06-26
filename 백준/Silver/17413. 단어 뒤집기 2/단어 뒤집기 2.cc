#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    string str;
    getline(cin, str);
    vector<char> v_char;
    bool flag = false; // 태그인지 확인하는 변수

    for (int i = 0; i < str.length(); i++)
    {
        v_char.push_back(str[i]); // 문자를 벡터에 넣다가

        if (str[i] == '<')
        {                // 문자가 태그의 시작인 괄호라면
            flag = true; // 태그가 열렸다는 것을 표시
        }

        if (flag)
        {                      // 태그가 열린 상태이면서
            if (str[i] == '>') // 닫는 괄호가 나오면
            {
                flag = false; // 태그 닫기
                int size_f = v_char.size();
                for (int j = 0; j < size_f; j++)
                {
                    cout << v_char.front();       // 앞에서부터 출력
                    v_char.erase(v_char.begin()); // 출력한 문자 삭제
                }
            }
        }

        else
        { // 공백으로 구분되어있거나 문자열의 끝이거나 다음 문자가 '<'라면 거꾸로 출력
            if (str[i] == ' ' || i == str.length() - 1 || (i != str.length() - 1 && str[i + 1] == '<'))
            {
                int size_b = v_char.size();
                if (str[i] == ' ')
                {
                    v_char.pop_back();                  // 공백 삭제
                    v_char.insert(v_char.begin(), ' '); // 앞에 공백 넣기
                }
                for (int j = 0; j < size_b; j++)
                {
                    cout << v_char.back();
                    v_char.pop_back();
                }
            }
        }
    }
}