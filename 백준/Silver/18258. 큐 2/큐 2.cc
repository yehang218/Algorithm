#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int X;

void ProecssCommand(string command)
{
    if (command.compare("push") == 0)
    {
        cin >> X;
        q.push(X);
    }
    else if (command.compare("pop") == 0)
    {
        if (q.empty())
            cout << "-1" << "\n";
        else
        {
            cout << q.front() << "\n";
            q.pop();
        }
    }
    else if (command.compare("size") == 0)
    {
        cout << q.size() << "\n";
    }
    else if (command.compare("empty") == 0)
    {
        cout << (q.empty() ? 1 : 0) << "\n";
    }
    else if (command.compare("front") == 0)
    {
        cout << (q.empty() ? -1 : q.front()) << "\n";
    }
    else if (command.compare("back") == 0)
    {
        cout << (q.empty() ? -1 : q.back()) << "\n";
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string command;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> command;
        ProecssCommand(command);
    }
}