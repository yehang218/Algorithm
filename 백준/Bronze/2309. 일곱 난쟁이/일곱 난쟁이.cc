// 문제 분석
/*
 난쟁이들 9명중 진짜 7명을 찾아라
 7명 친구들의 키의 합은 100

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> statures;
int sum_stature = 0;

void output();

void input()
{
    int num = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> num;
        sum_stature += num;
        statures.push_back(num);
    }
}

void solve()
{
    for (int i = 0; i < statures.size(); i++)
    {
        for (int j = i + 1; j < statures.size(); j++)
        {
            if ((sum_stature - statures[i] - statures[j]) == 100)
            {
                statures.erase(statures.begin() + j);
                statures.erase(statures.begin() + i);
                output();
                return;
            }
        }
    }
}

void output()
{
    sort(statures.begin(), statures.end());
    for (int stature : statures)
    {
        cout << stature << "\n";
    }
}

int main(void)
{
    input();
    solve();
}