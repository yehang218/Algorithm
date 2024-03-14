#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

void solve(string str)
{
    int num = 0;
    if (str == "push_front")
    {
        cin >> num;
        dq.push_front(num);
    }

    else if (str == "push_back")
    {
        cin >> num;
        dq.push_back(num);
    }

    else if (str == "pop_front")
    {
        if (dq.empty())
            cout << "-1";
        else
        {
            cout << dq.front();
            dq.pop_front();
        }
        cout << "\n";
    }

    else if (str == "pop_back")
    {
        if (dq.empty())
            cout << "-1";
        else
        {
            cout << dq.back();
            dq.pop_back();
        }
        cout << "\n";
    }

    else if (str == "size")
    {
        cout << dq.size() << "\n";
    }

    else if (str == "empty")
    {
        cout << dq.empty() ? 1 : 0;
        cout << "\n";
    }

    else if (str == "front")
    {
        if (dq.empty())
            cout << "-1";
        else
        {
            cout << dq.front();
        }
        cout << "\n";
    }

    else if (str == "back")
    {
        if (dq.empty())
            cout << "-1";
        else
        {
            cout << dq.back();
        }
        cout << "\n";
    }
}

int main(void)
{
    int N;
    cin >> N;

    string str = "";
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        solve(str);
    }
}