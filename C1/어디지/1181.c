#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void str_swap(char *str1, char *str2)
{
    char temp[50];

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int main(void)
{
    int N;
    int i, j;
    char **str;

    scanf("%d",&N);

    str = (char **)malloc(sizeof(char *)* (N+1));
    for(i = 0; i<N;i++)
        str[i] = (char *)malloc(sizeof(char) * 50);
    
    for(i = 0; i < N; i++)
        scanf("%s", str[i]);

    for(i=0;i < N - 1;i++)
    {
        for(j = 0; j < N -i -1;j++)
        {
            if(strlen(str[j]) > strlen(str[j+1]))
            {
                str_swap(str[j], str[j+1]);
            }

            else if(strlen(str[j]) == strlen(str[j+1]))
            {
                if(strcmp(str[j],str[j+1]) > 0)
                   str_swap(str[j],str[j+1]);
            }
        }
    }

    for(i=0;i < N;i++)
    {
        if(i != N - 1 &&  (strcmp(str[i],str[i+1]) == 0))
            continue;
        printf("%s",str[i]);
        if(i!=N-1)
            printf("\n");
    }
        

    for(i = 0;i<N;i++)
        free(str[i]);
    free(str);

    return (0);
}