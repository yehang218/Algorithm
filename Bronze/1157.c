#include<stdio.h>

int main(void)
{
    char str[1000000];
    int alpha[127] = {0};
    int num = 0;
    int max = 0;
    int result = 0;

    scanf("%s",str);

    for(int i =0; str[i]; i++)
    {
        num = 0;
        if(str[i] >='a' && str[i] <='z')
            num = -32;
        num = num + str[i];
        alpha[num]++;
    }
    for(int i =0; i < 91 ; i++)
    {
        if(max < alpha[i])
        {
            max = alpha[i];
            result = i;
        }
    }
    for(int i =0; i<91; i++)
    {
        if(max == alpha[i] && (i != result))
        {
             printf("?");
             return (0);
        }
    }
    printf("%c", result);
    return (0);
}