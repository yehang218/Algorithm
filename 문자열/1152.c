#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[1000000];
    int count = 0;
    int i = 0;
    int len = 0;

    scanf("%[^\n]", str);
    len = strlen(str);

    if(len == 1 && str[0] == ' ')
    {
        printf("0");
        return (0);
    }
        
    while(str[i])
    {
        if(str[i] == ' ' && i != 0 && str[i+1] != '\0')
            count++;
        i++;
    }
    printf("%d", count + 1);
    return (0);
}