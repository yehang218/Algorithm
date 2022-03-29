#include<stdio.h>

int main(void)
{
    int i = 0;
    int num[9]={0};
    int max = 0;
    int max_i = 0;

    for(i = 0; i < 9; i++)
    {
        scanf("%d",&num[i]);
    }
    max = num[0];
    for(i=0;i<9;i++)
    {
        if (max <= num[i])
        {
            max = num[i];
            max_i = i + 1;
        }
    }
    printf("%d\n%d",max,max_i);
    return (0);
}