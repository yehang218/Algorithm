#include <iostream>
#include <queue>

using namespace std;

int T;

int solve(int N, int M)
{
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    int priority;
    for (int i = 0; i < N; i++)
    {
        cin >> priority;
        pq.push(priority);
        q.push({i, priority});
    }

    int printOrder = 0;
    while (!q.empty())
    {
        int paperNum = q.front().first;
        int paperPriority = q.front().second;
        q.pop();

        if (pq.top() != paperPriority)
            q.push({paperNum, paperPriority});
        else if (pq.top() == paperPriority)
        {
            pq.pop();
            printOrder++;
            if (M == paperNum)
                return printOrder;
        }
    }
    return 0;
}

void input()
{
    int N, M;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        cout << solve(N, M) << "\n";
    }
}

int main(void)
{
    input();
}