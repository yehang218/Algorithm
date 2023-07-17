#include <iostream>
#include <string>

using namespace std;

int N;
int check;
int i = 666;
string str;

void input()
{
    cin >> N;
}

void findTitle()
{
    while (1)
    {
        str = to_string(i);

        // 666이 있다면
        if (str.find("666") != string::npos)
            check++;

        if (check == N)
        {
            cout << i;
            return;
        }

        i++;
    }
}

int main(void)
{
    input();
    findTitle();
}