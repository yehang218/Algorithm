#include <iostream>

using namespace std;

int main(void)
{
    int T;
    char A, comma, B;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> comma >> B;
        cout << (A - '0') + (B - '0') << "\n";
    }
}