#include<stdio.h>

int main(void)
{
    int N;

    scanf("%d", &N);
    for(int j = 1; j <= N ; j++)
    {
        for(int k = 0 ; k < N - j ; k++)
              printf(" ");
        for(int k = 0 ; k < j; k++)
            printf("*");
        printf("\n");    
    }
    return (0);
}