#include <iostream>

using namespace std;

int N, M;
bool bulbState[4001];

void ExecuteCommand(int a, int b, int c)
{
    switch (a)
    {
    case 1:
        bulbState[b] = c ? true : false;
        break;

    case 2:
        for (int i = b; i <= c; i++)
        {
            bulbState[i] = !bulbState[i];
        }
        break;

    case 3:
        for (int i = b; i <= c; i++)
            bulbState[i] = false;
        break;

    case 4:
        for (int i = b; i <= c; i++)
            bulbState[i] = true;
        break;

    default:
        break;
    }
}

void input()
{
    int check = 0;
    int a, b, c;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> check;
        bulbState[i] = check ? true : false;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        ExecuteCommand(a, b, c);
    }
}

void output()
{
    for (int i = 1; i <= N; i++)
    {
        cout << bulbState[i] ? 1 : 0;
        cout << " ";
    }
}

int main(void)
{
    input();
    output();
}