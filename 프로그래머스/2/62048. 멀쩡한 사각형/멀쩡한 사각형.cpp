// 문제 분석
/*
일정한 패턴이 가로와 세로의 최대 공약수만큼 반복됨!
이 하나의 패턴에서 잘라지는 사각형 개수는 ((가로 / 최대공약수) + (세로 / 최대공약수) - 1) 
    -1 을 하는 이유 : 가로 시작점 = 세로 시작점 -> 중복!
    -1 하는 이유 설명 잘되어있는 블로그 -> https://unagi-zoso.tistory.com/41
=> 총 잘라지는 사각형의 개수 = ((가로 / 최대 공약수) + (세로 / 최대 공약수) - 1) * 최대공약수
*/
#include <algorithm>

using namespace std;

long long findMaxDiv(long long a, long long b)
{
    long long num;

    if(b % a == 0) return a;
    while(a != 0)
    {
        num = b % a;
        b = a;
        a = num;
    }
    return b;
}

long long solution(int w,int h)
{
    long long max_div = findMaxDiv(min(w,h), max(w,h));
    long long cut_square = w + h - max_div;

    return (long long)w * h - cut_square;
}