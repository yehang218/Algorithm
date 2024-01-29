#include <iostream>
#include <vector>

using namespace std;

int result = 0;

void dfs(vector<int> &number, int sum, int index, int cnt)
{
    if (cnt == 3)
    {
        if (sum == 0)
        {
            result++;
        }
        return;
    }

    for (int i = index; i < number.size(); i++)
    {
        dfs(number, sum + number[i], i + 1, cnt + 1);
    }
}

int solution(vector<int> number)
{
    for (int i = 0; i < number.size(); i++)
    {
        dfs(number, number[i], i + 1, 1);
    }

    return result;
}