#include<stdio.h>

int main(void)
{
    int N;
    int help_num;
    int num = 0;

    scanf("%d", &N);

    for(int i = 0; i<N; i++)
    {  
        num = i;
        help_num = i;
        while(help_num > 0)
        {
            num = num + (help_num % 10);
            help_num = help_num / 10;
        }
        if(num == N){
            printf("%d", i);
            return 0;
        }
    }

    printf("0");

    return 0;
}