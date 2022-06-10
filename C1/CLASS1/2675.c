#include<stdio.h>

int main(void)
{
    int T;
    int R;
    int i, j = 0, k = 0;
    char str[20];

    scanf("%d", &T);
    for(i = 0; i < T; i++)
    {
        scanf("%d", &R);
        scanf("%s",str);

        for(j = 0; str[j]; j++)
        {
            for(k = 0; k<R; k++)
            {
                printf("%c",str[j]);
            }
        }
        if(i != T-1)
            printf("\n");
    }
    return (0);
}