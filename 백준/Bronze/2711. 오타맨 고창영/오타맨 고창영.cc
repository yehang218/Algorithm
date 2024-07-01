#include <iostream>

using namespace std;

int main(void)
{
    int T;
    int MissSpellPos;
    string MissSpell;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> MissSpellPos;
        cin >> MissSpell;

        MissSpell.erase(MissSpell.begin() + MissSpellPos - 1);
        cout << MissSpell << "\n";
    }
}