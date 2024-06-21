#include <iostream>

using namespace std;

int main(void)
{
    int T;
    string str;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int sum = 0;
        int score = 0;
        cin >> str;

        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] != 'X')
            {
                score++;
                sum = sum + score;
            }
            else
                score = 0;
        }

        cout << sum << "\n";
    }
}