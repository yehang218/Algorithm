#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

int T;
string p;
int n;
string x;
deque<string> split_x;

void solve(string p, deque<string> x);

deque<string> parsing(string x)
{
    deque<string> result;

    x.pop_back();
    x.erase(x.begin());

    istringstream iss(x); // 초기화(iss에 x 대입)
    string buffer;

    while (getline(iss, buffer, ','))
    { //','를 기준으로 buffer에 담기
        result.push_back(buffer);
    }
    return result;
}

void input()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> p;
        cin >> n;
        cin >> x;

        split_x.clear();
        split_x = parsing(x);

        solve(p, split_x);
    }
}

void solve(string p, deque<string> x)
{
    bool reverse_x = false;
    int len = p.length();
    for (int i = 0; i < len; i++)
    {
        if (p[i] == 'R')
        {
            reverse_x = !reverse_x;
        }

        else if (p[i] == 'D')
        {
            if (x.empty())
            {
                cout << "error"
                     << "\n";
                return;
            }
            if (reverse_x)
            {
                x.pop_back();
            }
            else
                x.pop_front();
        }
    }

    cout << "[";

    int index = 0;
    int size = x.size();
    while (!x.empty())
    {
        if (reverse_x)
        {
            cout << x.back();
            x.pop_back();
        }
        else
        {
            cout << x.front();
            x.pop_front();
        }
        if (index != size - 1)
            cout << ",";
        index++;
    }
    cout << "]"
         << "\n";
}

int main(void)
{
    input();
}