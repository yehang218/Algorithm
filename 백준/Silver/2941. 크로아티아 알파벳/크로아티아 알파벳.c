#include<stdio.h>
#include<string.h>

int check_ca(char *str, int len)
{
    int count = 0;

    for(int i = 0; i < len ; i++)
    {
        if(str[i] == 'c' && i < len - 1) {
            if(str[i+1] == '=' || str[i+1] == '-')
                i++;
        }
        else if(str[i] == 'd') {
            if(i < len -2 && str[i+1] == 'z' && str[i+2] == '=')
                i+=2;
            else if(i < len -1 && str[i+1] =='-')
                i++;
        }
        else if((str[i] == 'l' || str[i] == 'n') && i < len -1) {
            if(str[i+1] == 'j')
                i++;
        }
        else if(str[i] == '=' && i > 0)
            if(str[i-1] == 's' || str[i-1] == 'z')
                continue;
        count++;
    }

    return count;
}

int main(void)
{
    char str[101];
    int len;

    scanf("%s",str);
    len = strlen(str);
    printf("%d",check_ca(str, len));

    return (0);
}