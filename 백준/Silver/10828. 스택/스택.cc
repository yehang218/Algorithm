#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int num;

void solve(string command)
{
    if (!command.compare("push"))
    {
        cin >> num;
        s.push(num);
    }

    else if (!command.compare("pop"))
    {
        if (s.empty())
            cout << "-1"
                 << "\n";
        else
        {
            cout << s.top() << "\n";
            s.pop();
        }
    }

    else if (!command.compare("size"))
        cout << s.size() << "\n";

    else if (!command.compare("empty"))
        cout << (s.empty() ? 1 : 0) << "\n";

    else if (!command.compare("top"))
        cout << (s.empty() ? -1 : s.top()) << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string command = "";

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> command;
        solve(command);
    }
}