#include<stdio.h>

int main(void)
{
    char str[100];
    int i = 0;
    int alpha[26];
    int num;

    scanf("%s",str);

    for(i = 0; i < 26; i++)
    {
        alpha[i] = -1;
    }
    
    for(i = 0; str[i]; i++)
    {
        num = str[i] - 97;
        if(alpha[num] != -1)
            continue;
        alpha[num] = i;
    }
    
    i = 0;
     for(i = 0; i < 26; i++)
    {
        printf("%d", alpha[i]);
        if(i != 25)
            printf(" ");
    }
    return (0);
}