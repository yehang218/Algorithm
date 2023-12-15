#include <iostream>

using namespace std;

int main(void)
{
    int year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int x, y;

    cin >> x >> y;

    int sum = 0;

    for (int i = 0; i < x - 1; i++)
    {
        sum += year[i];
    }

    sum += y;

    cout << days[sum % 7] << "\n";
}