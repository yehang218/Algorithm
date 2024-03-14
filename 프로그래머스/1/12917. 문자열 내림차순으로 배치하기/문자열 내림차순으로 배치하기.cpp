#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s)
{
    string answer = "";
    vector<char> v_char;
    for (auto c : s)
    {
        v_char.push_back(c);
    }
    sort(v_char.begin(), v_char.end(), greater<>());
    for (auto c : v_char)
    {
        answer += c;
    }
    return answer;
}