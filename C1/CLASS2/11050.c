#include<stdio.h>

int main(void)
{
    int N, K;
    int np = 1, nmkp = 1, kp = 1;

    scanf("%d %d", &N, &K);

    for(int i = 1;i <=N; i++)
        np = np * i;
    for(int i = 1; i<=N-K; i++)
        nmkp = nmkp * i;
    for(int i = 1; i<=K; i++)
        kp = kp * i;
    
    printf("%d", np / (nmkp * kp));
    return 0 ;
}