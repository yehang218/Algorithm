#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
stack<int> s_num;
vector<char> v_calc;

void output()
{
    for (char calc : v_calc)
    {
        cout << calc << "\n";
    }
}

void solve()
{
    int num;
    int top = 1;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        for (top; top <= num; top++)
        {
            v_calc.push_back('+');
            s_num.push(top);
        }

        if (s_num.top() == num)
        {
            v_calc.push_back('-');
            s_num.pop();
        }
        else
        {
            cout << "NO";
            return;
        }
    }

    output();
}

int main(void)
{
    solve();
}