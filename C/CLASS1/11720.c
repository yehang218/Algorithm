#include<stdio.h>

int main(void)
{
    int N;
    char c[100];
    int result = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf(" %c", &c[i]);
        result = result + (c[i] - '0');
    }
    printf("%d",result);

    return (0);
}