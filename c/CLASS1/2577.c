#include<stdio.h>

int check_ten(int num)
{
    int i = 0;

    while (num > 0)
    {
        num = num / 10;
        i++;
    }

    return (i);
}

int main(void)
{
    int A,B,C;
    int mul;
    int num[10] = {0};
    int digit_num = 0;

    scanf("%d %d %d", &A, &B, &C);
    mul = A * B * C;
    digit_num = check_ten(mul);

    for(int i = 0; i < digit_num; i++)
    {
        num[mul%10]++;
        mul = mul / 10;
    }

    for (int i = 0; i< 10; i++)
    {
        printf("%d\n", num[i]);
    }
    return (0);
}