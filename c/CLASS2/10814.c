#include<stdio.h>
#include<string.h>

void switch_person(int *age1, int *age2, char *str1, char *str2)
{
    int temp = *age1;
    char *str = str1;

    *age1 = *age2;
    *age2 = temp;

    str1 = str2;
    str2 = str;
}

int main(void)
{
    int N;
    int age[100000];
    char str[100000];

    scanf("%d", &N);
    for(int i = 0; i<N; i++)
        scanf("%d %s", &age[i], str[i]);
    
    for(int i = 0; i<N-1; i++)
    {
        for(int j = 0; j < N - i -1 ; j++)
        {
            if(age[j] > age[j+1])
            {
                switch_person(&age[j], &age[j+1],str[j],str[j+1]);
            }
            else if(age[j] == age[j+1]){
                if(strcmp(str[j], str[j+1]) > 0){
                    switch_person(&age[j], &age[j+1],str[j],str[j+1]);
                }
            }
        }
    }

    for(int i = 0; i<N; i++)
    {
        printf("%d %s\n",age[i], str[i]);
    }
    return (0);
}