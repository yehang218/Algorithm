#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int N;
    int num;
    int result = 0;

    scanf("%d", &N);
    scanf("%lld", &num);
    while(N--)
    {
        result = result + (num % 10);
        num = num / 10;
    }
    printf("%d",result);
}