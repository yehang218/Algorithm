#include <iostream>
#include <queue>

using namespace std;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    priority_queue<int> pq;

    int x;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if (x != 0)
            pq.push(x);
        else
        {
            if (pq.empty())
            {
                cout << "0"
                     << "\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}

int main(void)
{
    input();
}