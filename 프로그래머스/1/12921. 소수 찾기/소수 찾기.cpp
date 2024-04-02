#include <string>
#include <vector>
#include <cmath>

using namespace std;

int check[1000001];

int findDecimal(int n)
{
    int answer = 0;

    for (int i = 2; i <= n; i++)
    {
        if (!check[i])
            answer++;
    }
    return answer;
}

int solution(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (!check[i])
        {
            for (int k = i * i; k <= n; k += i)
            {
                check[k] = 1;
            }
        }
    }

    return findDecimal(n);
}
