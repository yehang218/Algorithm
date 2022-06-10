#include<stdio.h>

int d(int num)
{
    int result = 0;

    result = num;
    while (num > 0)
    {
        result = result + (num % 10);
        num = num / 10;
    }
    return (result);
}

int main(void)
{
    int check[10001] = {0};
    int num = 0;

    for (int i = 1; i <= 10000; i++)
    {
        num = d(i);
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