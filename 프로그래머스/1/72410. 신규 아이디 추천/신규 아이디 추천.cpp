#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

// 3 <= 아이디 길이 <=15
// 알파벳 소문자, 숫자 -, _, .만 가능
// . 은 처음과 끝 사용 X, 연속 X

bool check_str_cond(char c)
{
    if ('a' <= c && c <= 'z')
        return true;
    if ('0' <= c && c <= '9')
        return true;
    if (c == '-' || c == '_' || c == '.')
        return true;

    return false;
}

string solution(string new_id)
{
    string answer = "";
    string temp = "";

    // 1단계
    for (char c : new_id)
        answer += tolower(c);

    // 2단계
    for (char c : answer)
    {
        if (check_str_cond(c))
            temp += c;
    }
    answer = temp;
    temp = "";

    // 3단계
    for (int i = 0; i < answer.size(); i++)
    {
        if (answer[i] == '.' && temp[temp.size() - 1] == '.')
            continue;
        temp += answer[i];
    }
    answer = temp;
    temp = "";

    // 4단계
    if (answer[0] == '.')
        answer.erase(answer.begin());
    if (answer[answer.size() - 1] == '.')
        answer.erase(answer.end() - 1);

    // 5단계
    if (answer.size() == 0)
        answer = "a";

    // 6단계
    if (answer.size() >= 16)
        answer.erase(answer.begin() + 15, answer.end());
    if (answer[answer.size() - 1] == '.')
        answer.erase(answer.end() - 1);

    // 7단계
    if (answer.size() <= 2)
    {
        char end = answer[answer.size() - 1];
        while (answer.size() < 3)
            answer += end;
    }

    return answer;
}
