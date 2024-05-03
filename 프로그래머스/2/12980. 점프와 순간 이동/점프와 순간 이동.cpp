// 문제 분석
/*
 점프 : K칸 앞 -> 건전지 사용량 K만큼 감소
 순간이동 : 현재까지 온 거리 * 2 -> 건전지 사용량 감소 X
 N만큼 갈 때, 건전지 사용량 최소로?

 => n을 2로 나누면서 나머지가 1인 경우만 사용량 증가
*/

#include <iostream>

using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while(n > 0)
    {
        ans = (n & 1 ? ans + 1 : ans);
        n = n / 2;
    }

    return ans;
}