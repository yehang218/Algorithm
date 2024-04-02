#include <iostream>

using namespace std;

int findMaxDiv(int min, int max)
{
    int remain = 0;
    while (min != 0)
    {
        remain = max % min;
        max = min;
        min = remain;
    }
    return max;
}

int main(void)
{
    int a, b;
    cin >> a >> b;

    int maxDiv = findMaxDiv(min(a, b), max(a, b));
    cout << maxDiv << "\n";
    cout << a * b / maxDiv;
}