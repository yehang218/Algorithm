#include<stdio.h>

int main(void)
{
    int N;
    int n;
    int new_num = -1;
    int count = 0;
    int num;

    scanf("%d", &N);

    num = N;
    while(new_num != N)
    {
        if(new_num != -1)
            num = new_num;
        n = (num / 10) + (num % 10);
        new_num = ((num % 10) * 10) + (n % 10);
        count++;
    }
    printf("%d", count);
    return (0);
}