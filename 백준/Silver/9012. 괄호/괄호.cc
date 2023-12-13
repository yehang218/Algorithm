#include <iostream>
#include <stack>
#include <string>

using namespace std;

int T;

string solve(string bracket)
{
    stack<char> stack_bracket;

    for (int i = 0; i < bracket.length(); i++)
    {
        if (bracket[i] == '(')
        {
            stack_bracket.push('(');
        }
        else if (bracket[i] == ')')
        {
            if (stack_bracket.empty())
            {
                return "NO";
            }

            if (stack_bracket.top() == '(')
            {
                stack_bracket.pop();
            }
        }
    }

    if (stack_bracket.empty())
        return "YES";
    else
        return "NO";
}

int main(void)
{
    int T;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string brackets;
        cin >> brackets;
        cout << solve(brackets) << "\n";
    }
}