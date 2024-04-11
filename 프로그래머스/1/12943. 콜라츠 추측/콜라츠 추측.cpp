#include <string>
#include <vector>

using namespace std;

int solution(int num)
{
    long long n = num;
    int count = 0;
    
    if (n == 1) return 0;
    while (n != 1)
    {
        if (count == 500) return -1;
        count++;
        n = n & 1 ? (n * 3 + 1) : n / 2;
    }

    return count;
}