#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s)
{
    string answer = "";
    int index = 0;

    for (auto cAlphabet : s)
    {
        if (cAlphabet == ' ')
        {
            index = -1;
        }
        answer += (index % 2) ? tolower(cAlphabet) : toupper(cAlphabet);
        index++;
    }

    return answer;
}