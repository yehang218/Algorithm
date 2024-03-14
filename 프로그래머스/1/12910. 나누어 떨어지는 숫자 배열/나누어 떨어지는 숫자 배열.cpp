#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;

    for (auto num : arr)
    {
        if (num % divisor == 0)
            answer.push_back(num);
    }
    if (answer.size() == 0)
        answer.push_back(-1);
    sort(answer.begin(), answer.end(), less<int>());

    return answer;
}