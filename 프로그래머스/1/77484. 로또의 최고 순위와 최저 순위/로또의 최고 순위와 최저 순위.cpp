#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    int correct = 0;
    int erase = 0;

    for (int lotto : lottos)
    {

        if (lotto == 0)
        {
            erase++;
            continue;
        }

        if (find(win_nums.begin(), win_nums.end(), lotto) == win_nums.end())
            continue;
        correct++;
    }
    
    int max_lank = 7 - (correct + erase);
    int min_lank = 7 - correct;

    if (max_lank == 7) max_lank = 6;
    if (min_lank == 7) min_lank = 6;
    answer.push_back(max_lank);
    answer.push_back(min_lank);

    return answer;
}