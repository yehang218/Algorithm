#include<stdio.h>

int check_ten(int num)
{
    int digit = 0;
    while(num > 0)
    {
        num =num / 10;
        digit++;
    }
    return (digit);
}

int main(void)
{
    int num1, num2;
    int c_num2;
    scanf("%d %d", &num1, &num2);
    c_num2 = num2;
    int digit = check_ten(num1);

    for(int i = 0; i<digit; i++)
    {
        printf("%d", num1 * (num2 % 10));
        printf("\n");
        num2 = num2 / 10;
    }
    printf("%d", (num1 * c_num2));

    return (0);
}