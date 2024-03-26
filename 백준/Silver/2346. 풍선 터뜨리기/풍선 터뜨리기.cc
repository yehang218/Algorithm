#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int N;
deque<pair<int, int>> dq_balloon;

void input()
{
    int n;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> n;
        dq_balloon.push_back({i, n});
    }
}

void solve()
{
    while (!dq_balloon.empty())
    {
        int index = dq_balloon.front().first;
        int paper = dq_balloon.front().second;
        dq_balloon.pop_front();
        cout << index << " ";

        if (dq_balloon.empty())
            break;

        bool check = paper > 0 ? true : false;
        paper = paper > 0 ? paper - 1 : abs(paper);
        for (int i = 0; i < paper; i++)
        {
            if (check)
            {
                dq_balloon.push_back(dq_balloon.front());
                dq_balloon.pop_front();
            }
            else
            {
                dq_balloon.push_front(dq_balloon.back());
                dq_balloon.pop_back();
            }
        }
    }
}

int main(void)
{
    input();
    solve();
}