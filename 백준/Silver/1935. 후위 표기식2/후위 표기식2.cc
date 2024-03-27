#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;

string str;
vector<double> v_num;
stack<double> s_num;

void input()
{
    int N;
    double num;

    cin >> N;
    cin >> str;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v_num.push_back(num);
    }
}

double calc(double num1, double num2, char calc)
{
    if (calc == '+')
        return num1 + num2;
    else if (calc == '-')
        return num1 - num2;
    else if (calc == '*')
        return num1 * num2;
    else if (calc == '/')
        return num1 / num2;
    return 0;
}

double solve()
{
    double num1;
    double num2;

    for (int i = 0; i < str.length(); i++)
    {
        // 연산자라면
        if (!isalpha(str[i]))
        {
            num2 = s_num.top();
            s_num.pop();
            num1 = s_num.top();
            s_num.pop();
            s_num.push(calc(num1, num2, str[i]));
        }

        else
            s_num.push(v_num[str[i] - 'A']);
    }

    return s_num.top();
}

int main(void)
{
    input();
    cout << fixed;
    cout.precision(2);
    cout << solve();
}