#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int small_bracket = 0; // 소괄호 개수
    int big_bracket = 0;   // 대괄호 개수

     while (true)
    {
        string str;
        vector<char> v_char;
        v_char.clear();
        getline(cin, str);

        if(str[0] == '.') break; // 종료조건

        int i = 0;
        for (i; i < str.length(); i++)
        {
            if (str[i] == '.')
            {
                break;
            }

            if (str[i] == '(' || str[i] == '[')
            {
                v_char.push_back(str[i]);
            }
            else if (str[i] == ')')
            {
                if (v_char.size() != 0 && v_char.back() == '(')
                    v_char.pop_back();
                else {
                    cout << "no" << endl;
                    break;
                }
            }
            else if (str[i] == ']')
            {
                if (v_char.size() != 0 && v_char.back() == '[')
                    v_char.pop_back();
                else {
                    cout << "no" << endl;
                    break;
                }
            }
        }

        if(v_char.size() == 0 && i == str.length() - 1) cout << "yes" << endl; // 괄호가 모두 닫혔고 끝까지 도달한 경우
        else if(v_char.size() != 0 && i == str.length() - 1) cout << "no" << endl; // 열린 괄호가 하나라도 남아있는데 문장의 끝에 도달한 경우
    }
}