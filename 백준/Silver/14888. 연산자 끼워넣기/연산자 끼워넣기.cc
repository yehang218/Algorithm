#include <iostream>

using namespace std;

int N;
int num[12];
int cal[4];

int maxStandard = -1000000001;
int minStandard = 1000000001;

void solve(int index, int result)
{
    if (index == N)
    {
        if (result > maxStandard)
            maxStandard = result;
        if (result < minStandard)
            minStandard = result;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (cal[i] == 0) // 연산자가 없으면 넘어가기
            continue;
        cal[i]--;
        if (i == 0)
            solve(index + 1, result + num[index]);
        else if (i == 1)
            solve(index + 1, result - num[index]);
        else if (i == 2)
            solve(index + 1, result * num[index]);
        else if (i == 3)
            solve(index + 1, result / num[index]);
        cal[i]++;
    }
}

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> cal[i];
    }

    solve(1, num[0]); // 0,0 으로 두는 경우 첫 값이 0 * num[0]이 될 수도 있음
    cout << maxStandard << "\n";
    cout << minStandard;
}