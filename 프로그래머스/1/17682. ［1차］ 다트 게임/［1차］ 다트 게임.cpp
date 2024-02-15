#include <string>
#include <vector>

using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    int tempNum = 0;

    vector<int> vAnswer;

    for (int i = 0; i < dartResult.length(); i++)
    {
        if (dartResult[i] >= 0 && dartResult[i] <= '9')
        {
            tempNum = dartResult[i] - '0';
            if (tempNum == 1 && dartResult[i + 1] == '0')
            {
                tempNum = 10;
                i++;
            }
        }
        if (dartResult[i] == 'S')
            vAnswer.push_back(tempNum);
        else if (dartResult[i] == 'D')
            vAnswer.push_back(tempNum * tempNum);
        else if (dartResult[i] == 'T')
            vAnswer.push_back(tempNum * tempNum * tempNum);
        else if (dartResult[i] == '*')
        {
            vAnswer[vAnswer.size() - 2] = vAnswer[vAnswer.size() - 2] * 2;
            vAnswer[vAnswer.size() - 1] = vAnswer[vAnswer.size() - 1] * 2;
        }
        else if (dartResult[i] == '#')
            vAnswer[vAnswer.size() - 1] = vAnswer[vAnswer.size() - 1] * (-1);
    }

    for (int i = 0; i < vAnswer.size(); i++)
    {
        answer += vAnswer[i];
    }

    return answer;
}