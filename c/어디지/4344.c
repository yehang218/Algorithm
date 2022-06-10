#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int C;
    int i ,j;
    int score[1000];
    int *N;
    float avg[1000];
    float result[1000] ={0};

    scanf("%d", &C);

    N = (int *)malloc(sizeof(int) * C);

    for(i = 0;i < C;i++){
        scanf("%d",&N[i]);
        avg[i] = 0;
        for(j = 0; j < N[i]; j++)
        {  
            scanf("%d",&score[j]);
            avg[i] = (float)score[j] + avg[i];
        }

        avg[i] = avg[i] / (float)N[i];

        for(j = 0; j < N[i];j++)
        {
            if(avg[i] < score[j])
                result[i]++;
        }
    }

    for(i = 0; i<C;i++)
    {
       printf("%.3lf%%",(result[i] / (float)N[i]) *100);
       if(i != C-1)
        printf("\n");
    }
    free(N);
    return (0);
}