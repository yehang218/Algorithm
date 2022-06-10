#include<stdio.h>
#include<string.h>

int main(void)
{
    int ten;
    char num[5] = {0};
    int check;
    int j;

    while(1)
    {
        check = 1;
        scanf("%s", num);

        if(!strcmp(num, "0"))  return 0;
        ten = strlen(num);
        j = ten - 1;
        for(int i = 0; i <= ten / 2; i++)
        {
            if(num[i] != num[j]){
                printf("no\n");
                check = 0;
                break;
            }
            j--;
        }
        if(check)
            printf("yes\n");
    }
    return 0;
}