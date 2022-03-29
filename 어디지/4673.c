#include<stdio.h>

int main(void)
{
    int check[10001] = {0};
    int num = 0;
    int help_num;

    for (int i = 1; i <= 10000; i++)
    {
        num = i;
        help_num = i;
        while(help_num > 0)
        {
            num = num + (help_num % 10);
            help_num = help_num / 10;
        }
        if(num <= 10000)
            check[num] = 1;
    }

    for(int i = 1; i <= 10000; i++)
    {
        if(!check[i])
            printf("%d\n", i);
    }
    return (0);
}