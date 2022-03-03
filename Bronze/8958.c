#include<stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, i, j;
    char **OX;
    int score = 0;
    int *result;

    scanf("%d", &N);
    result = (int *)malloc(sizeof(int) * N);
    OX = (char **)malloc(sizeof(char *) * (N+1));
    for(i = 0; i<N;i++)
        OX[i] = (char *)malloc(sizeof(char) * 80);
    
    for(i=0;i<N;i++)
    {
        scanf("%s", OX[i]);
    }

    for(i = 0; i<N; i++)
    {
        score = 0;
        for(j = 0; OX[i][j];j++)
        {
            if(OX[i][j] == 'O')
            {
                score++;
                result[i] = result[i] + score;
            }
            else
                score = 0;
        }
    }

    for(i = 0; i<N;i++)
        printf("%d\n",result[i]);

    for(i = 0;i<N;i++)
        free(OX[i]);
    free(OX);
    free(result);
    return (0);
}