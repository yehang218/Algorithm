#include<stdio.h>

int main(void)
{
    int N;
    int num[1000];
    int temp = 0;

    scanf("%d", &N);
    for(int i = 0 ; i<N; i++)
        scanf("%d", &num[i]);

    for(int i = 0; i<N-1; i++)
    {
        for(int j = 0; j < N-i-1 ;j++)
        if(num[j] > num[j+1])
        {
            temp = num[j];
            num[j] = num[j+1];
            num[j+1] = temp;
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        printf("%d\n", num[i]);
    }
    return (0);
}