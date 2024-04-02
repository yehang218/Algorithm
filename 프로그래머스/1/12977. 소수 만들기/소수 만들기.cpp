#include <vector>

using namespace std;

vector<int> sumNum(vector<int> nums)
{
    vector<int> sum;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                sum.push_back(nums[i] + nums[j] + nums[k]);
            }
        }
    }

    return sum;
}

bool check(int num)
{
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> sum = sumNum(nums);

    for (auto num : sum)
    {
        if (check(num))
            answer++;
    }

    return answer;
}
