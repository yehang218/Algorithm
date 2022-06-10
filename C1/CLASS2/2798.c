#include<stdio.h>

int main(void)
{
    int N, M;
    int num[300000];
    int sum = 0;
    int result = 0;

    scanf("%d %d", &N, &M);
    for(int i = 0; i<N; i++)
        scanf("%d", &num[i]);

    for(int i = 0; i<N; i++)
    {
        for(int j = i + 1; j < N ; j++)
        {
            for(int k = j+1; k < N ; k++)
            {
                sum= num[i] + num[j] + num[k];
                if(result < sum && sum <= M)
                    result = sum;
            }
        }
    }
    printf("%d", result);
    return (0);
}