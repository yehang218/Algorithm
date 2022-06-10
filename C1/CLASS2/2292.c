#include<stdio.h>

int main(void)
{
    int N;
    int plus = 6;
    int result = 1;
    int i = 1;
    
    scanf("%d", &N);
    while(i < N)
    {
        result++;
        i = i + plus;
        plus = plus + 6;
    }
    printf("%d",result);

    return (0);
}