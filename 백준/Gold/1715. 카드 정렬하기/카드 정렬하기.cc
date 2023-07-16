#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;
int result;

void input()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }
}

void cal()
{
    while (!pq.empty() && pq.size() != 1)
    {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        result = result + x + y;
        if (pq.empty())
            return;
        pq.push(x + y);
    }
}

int main(void)
{
    input();
    cal();
    cout << result << "\n";
}