#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int sign = 1;

    if (s[0] == '-' || s[0] == '+')
    {
        sign = (s[0] == '-') ? -1 : 1;
        s = s.substr(1, s.length());
    }

    return stoi(s) * sign;
}