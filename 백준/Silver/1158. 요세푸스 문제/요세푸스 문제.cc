#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;

queue<int> q;
vector<int> vAnswer;

void input()
{
    cin >> N >> K;
}

void FillQueue()
{
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }
}

void solve()
{
    while (!q.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        vAnswer.push_back(q.front());
        q.pop();
    }

    cout << "<";
    for (int i = 0; i < N; i++)
    {
        cout << vAnswer[i];
        cout << (i != N - 1 ? ", " : ">");
    }
}

int main(void)
{
    input();
    FillQueue();
    solve();
}