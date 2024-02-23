#include <string>

using namespace std;

bool solution(string s)
{
    int pCount = 0;
    int yCount = 0;

    for (auto sTemp : s)
    {
        if (tolower(sTemp) == 'p')
            pCount++;
        else if (tolower(sTemp) == 'y')
            yCount++;
    }

    return (pCount == yCount) ? true : false;
}