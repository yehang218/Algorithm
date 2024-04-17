#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 문제 분석
/*
1. 시작 시간, 끝나는 시간 입력
2. 이때, 겹치지 않게 하면서 회의실 사용할 수 있는 최대 개수는 몇개?
 => 끝나는 시간으로 정렬 (시작 시간이 빨라도 늦게 끝나면 최대로 만들 수 없기 때문)
 => 만약 끝나는 시간이 같다면, 시작하는 시간이 빠른 회의를 먼저 배정
*/

struct node
{
    int start;
    int end;

    bool operator<(const node &n) const
    {
        if (end == n.end)
            return start > n.start;
        return end > n.end;
    }
};

int N; // N(1 ≤ N ≤ 100000)
priority_queue<node> pq_meeting_time;

void input()
{
    int start, end = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> start >> end;
        pq_meeting_time.push({start, end});
    }
}

int solve()
{
    int last = 0;
    int answer = 0;

    while (!pq_meeting_time.empty())
    {
        int start = pq_meeting_time.top().start;
        int end = pq_meeting_time.top().end;
        pq_meeting_time.pop();

        if (start < last)
            continue;

        last = end;
        answer++;
    }

    return answer;
}

int main(void)
{
    input();
    cout << solve();
}