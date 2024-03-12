#include <iostream>
#include <queue>

using namespace std;

queue<int> qCards;

void initCards()
{
    int N = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        qCards.push(i);
    }
}

int solve()
{
    while (qCards.size() > 1)
    {
        qCards.pop();
        if (!qCards.empty())
        {
            qCards.push(qCards.front());
            qCards.pop();
        }
    }
    return qCards.front();
}

int main(void)
{
    initCards();
    cout << solve();
}