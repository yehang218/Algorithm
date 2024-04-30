#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    int upper = 'A' - 'a';

    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0 || s[i - 1] == ' ')
        {
            if ('a' <= s[i] && s[i] <= 'z')
                s[i] = s[i] + upper;
        }
        else if ('A' <= s[i] && s[i] <= 'Z')
            s[i] = s[i] - upper;
    }

    return s;
}