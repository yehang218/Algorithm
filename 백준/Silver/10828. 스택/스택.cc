#include <iostream>
#include <stack>
#include <string>

using namespace std;

int N; // 명령 개수
string str_command;
stack<string> s_strnum;

int main(void)
{
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        getline(cin, str_command);

        // push인 경우
        if (str_command.find("push") != string::npos)
        {
            string newstr = str_command.substr(5);
            s_strnum.push(newstr);
        }

        // pop인 경우
        else if (str_command.compare("pop") == 0)
        {
            if (s_strnum.empty() != 1)
            {
                cout << s_strnum.top() << "\n";
                s_strnum.pop();
            }
            else
                cout << "-1"
                     << "\n";
        }

        // size인 경우
        else if (str_command[0] == 's')
        {
            cout << s_strnum.size() << "\n";
        }

        // empty인 경우
        else if (str_command[0] == 'e')
        {
            if (s_strnum.empty() == 1)
                cout << "1"
                     << "\n";
            else
                cout << "0"
                     << "\n";
        }

        // top인 경우
        else if (str_command[0] == 't')
        {
            if (s_strnum.empty() != 1)
            {
                cout << s_strnum.top() << "\n";
            }
            else
                cout << "-1"
                     << "\n";
        }
    }
}