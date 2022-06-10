#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int N;
    int i, j, k = 1;

    char **str;
    
    int result[100] = {0};
    int num = 0;
    int check = 0;
    int word_count[100] = {0};

    scanf("%d",&N);

    str = (char **)malloc(sizeof(char *)* (N+1));
    for(i = 0; i<N;i++)
        str[i] = (char *)malloc(sizeof(char) * 100);
    for(i = 0; i<N; i++)
    {
        num = 0;
        int alpha[127] = {0};
        scanf("%s", str[i]);

        for(j = 0; str[i][j]; j++)
        {
            num = str[i][j];
            if(alpha[num] == 0)
                word_count[i]++;
           alpha[num]++;
        }

        j = 0;
        while(str[i][j])
        {
            k = 1;
            while(str[i][j] == str[i][j+k] && str[i][j+k])
                k++;
            num = str[i][j]; 
            if(alpha[num] == k)
                 result[i]++;   
            j = j + k;
        }

        if(word_count[i] == result[i])
            check++;
    }
   
    printf("%d", check);

    for(i = 0;i<N;i++)
        free(str[i]);
    free(str);
    return (0);
}