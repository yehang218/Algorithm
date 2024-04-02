#include <iostream>
#include <string>
#include <vector>

using namespace std;


int findMaxDiv(int n, int m)
{
    if(m % n == 0) return n;
    for(int i = n; i >=1; i--)
    {
        if(m % i == 0 && n % i == 0) return i;
    }
}


int findMinMul(int n, int m)
{
    int mulN = n;
    int mulM = m;

    if(m % n == 0) return m;
    for(int i = 1; i <= n; i++)
    {
        mulM = m * i;
        for(int j = 1; j <= m; j++)
        {
            mulN = n * j;
            if(mulM == mulN) return mulM;
        }
    }
}


vector<int> solution(int n, int m) {
    vector<int> answer; 
    answer.push_back(findMaxDiv(min(n,m), max(n,m)));
    answer.push_back(findMinMul(min(n,m), max(n,m)));
    return answer;
}