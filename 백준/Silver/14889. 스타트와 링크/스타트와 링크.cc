#include <iostream>
#include <vector>

using namespace std;

int N;
int standard = 2147483647;

vector<int> v[21];
int sum_start = 0;
int sum_link = 0;

bool team[21]; // true이면 start팀, false이면 link팀

void solve(int index, int now)
{
    /*
    if(index == N / 2){
        for(int i = 0; i < N; i++)
        {
            cout << team[i] << ' ';
        }
        cout << "\n";
        return;
    }
    */

    if (index == N / 2)
    {
        sum_start = 0;
        sum_link = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (team[i] && team[j]) // start인 팀 능력치 더하기
                    sum_start = sum_start + v[i].at(j);
                if (!team[i] && !team[j]) // link인 팀 능력치 더하기
                    sum_link = sum_link + v[i].at(j);
            }
        }
        int min = abs(sum_start - sum_link);
        if (min < standard)
            standard = min;
        return;
    }

    // 팀원이 중복되지 않게 팀 짜기
    // (1,2)나 (2,1)은 같은 팀이므로 now 사용해서 없애주기
    for (int i = now; i < N; i++)
    {
        team[i] = true;
        solve(index + 1, i + 1);
        team[i] = false;
    }
}

int main(void)
{
    int s = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> s;
            v[i].push_back(s);
        }
    }
    // cout << "\n";
    solve(0, 0);
    cout << standard;
}