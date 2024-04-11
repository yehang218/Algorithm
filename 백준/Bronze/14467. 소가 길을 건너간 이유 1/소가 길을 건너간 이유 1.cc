#include <iostream>
#include <queue>

using namespace std;

int N;
int lastLoc[11];
queue<pair<int, int>> q_observe;

void input()
{
    int num, loc; // 번호(1~10), 위치(왼-0/오-1)
    fill_n(lastLoc, 11, -1);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num >> loc;
        q_observe.push({num, loc});

        // 처음 들어온 위치면 저장
        if (lastLoc[num] == -1) lastLoc[num] = loc;
    }
}

int solve()
{
    int answer = 0;

    while (!q_observe.empty())
    {
        int num = q_observe.front().first;
        int loc = q_observe.front().second;
        q_observe.pop();

        // 기존 위치랑 다르면 ++
        if (lastLoc[num] != loc) answer++;
        lastLoc[num] = loc;
    }

    return answer;
}

int main(void)
{
    input();
    cout << solve();
}