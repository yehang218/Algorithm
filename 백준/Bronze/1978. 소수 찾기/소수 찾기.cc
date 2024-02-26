#include <iostream>

using namespace std;

int N;

bool checkDecimal(int num)
{
    if (num == 1)
        return false;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int findDecimal()
{
    int num = 0;
    int result = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (num == 1)
            result = result;
        else
            result = checkDecimal(num) ? result + 1 : result;
    }
    return result;
}

int main(void)
{
    cout << findDecimal();
}