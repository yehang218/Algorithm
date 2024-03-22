#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<long long> v_n;
    while(n > 0)
    {
        v_n.push_back(n%10);
        n = n / 10;
    }
    sort(v_n.begin(), v_n.end(), less<int>());

    answer = v_n[0];
    for(int i = 1 ;i < v_n.size(); i++)
    {
        answer = answer + (v_n[i] * pow(10,i));
    }

    return answer;
}