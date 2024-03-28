#include <string>
#include <vector>

using namespace std;

string makeTrit(int num)
{
    string str = "";
    while (num > 0)
    {
        str += to_string(num % 3);
        num = num / 3;
    }

    return str;
}

int solution(int n)
{
    int answer = 0;

    string str = makeTrit(n);
    int mul = 1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        answer += (str[i] - '0') * mul;
        mul *= 3;
    }

    return answer;
}
