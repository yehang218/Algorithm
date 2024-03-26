#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n)
{
    long long answer = 0;

    long long temp = sqrt(n);
    answer = (temp * temp == n) ? (temp + 1) * (temp + 1) : -1;

    return answer;
}
