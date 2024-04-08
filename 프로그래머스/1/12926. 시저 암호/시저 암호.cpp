#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    string answer = s;

    for (int i = 0; i < s.length(); i++)
    {
        if (answer[i] == ' ')
            continue;

        for (int j = 0; j < n; j++)
        {
            if (answer[i] == 'z' || answer[i] == 'Z')
            {
                answer[i] -= 25;
                continue;
            }
            answer[i]++;
        }
    }

    return answer;
}