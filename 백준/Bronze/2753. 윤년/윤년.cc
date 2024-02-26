#include <iostream>

using namespace std;

int main(void)
{
    int year = 0;

    cin >> year;
    cout << ((!(year % 4) && (year % 100)) || !(year % 400)) ? 1 : 0;
}