#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    int students[31] = {
        0,
    };

    for (int i = 0; i < reserve.size(); i++)
    {
        students[reserve[i]]++;
    }

    for (int i = 0; i < lost.size(); i++)
    {
        students[lost[i]]--;
    }

    for (int i = 1; i <= n; i++)
    {
        if (students[i] == -1)
        {
            if (students[i - 1] == 1)
            {
                students[i - 1] = 0;
                students[i] = 0;
            }
            else if (students[i + 1] == 1)
            {
                students[i + 1] = 0;
                students[i] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        answer = (students[i] != -1) ? answer + 1 : answer;
    }

    return answer;
}
