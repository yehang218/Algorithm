#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> mCompletion;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    for (auto partTemp : participant)
    {
        if (mCompletion.count(partTemp) != 0)
            mCompletion[partTemp] += 1;
        else
            mCompletion.insert({partTemp, 1});
    }

    for (auto compTemp : completion)
    {
        mCompletion[compTemp] -= 1;
    }

    for (auto partTemp : participant)
    {
        if (mCompletion[partTemp] != 0)
            return partTemp;
    }
    return answer;
}