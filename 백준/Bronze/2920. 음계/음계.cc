#include <iostream>

using namespace std;

int main(void)
{
    bool bAsc = true;
    bool bDes = true;

    int num[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> num[i];

        if (num[i] != i + 1)
            bAsc = false;
        if (num[i] != 8 - i)
            bDes = false;
    }

    if (!bAsc)
    {
        if (!bDes)
            cout << "mixed";
        else
            cout << "descending";
    }
    else
        cout << "ascending";
}