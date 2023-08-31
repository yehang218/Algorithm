#include <iostream>

using namespace std;

long long A, B, C;

long long cal(long long A, long long B)
{
    if (B == 0)
        return 1;
    if (B == 1)
        return A % C;

    long long temp = cal(A, B / 2);

    if (B % 2 == 0)
        return (temp * temp) % C;
    else
        return ((temp * temp) % C) * A % C;
}

int main(void)
{
    cin >> A >> B >> C;
    cout << cal(A, B);
}