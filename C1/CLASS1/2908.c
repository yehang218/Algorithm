#include<stdio.h>

int main(void)
{
    int num1, num2;
    int max = 0;
    int i = 0;
    int n1 = 0, n2 = 0;

    scanf("%d %d", &num1, &num2);
    for(i = 0; i < 3; i++)
    {
        n1 = n1 * 10 + (num1 % 10);
        n2 = n2 * 10 + (num2 % 10);
        num1 = num1 / 10;
        num2 = num2 / 10;
    }

    if(n1 > n2)
        max = n1;
    else max = n2;

    printf("%d", max);
    return (0);
}