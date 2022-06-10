#include<stdio.h>

int main(void)
{
    int num[8];
    int j = 8;
    int check = 0;

    for(int i= 0; i<8; i++)
        scanf("%d", &num[i]);
    for(int i = 0; i<8;i++)
    {
        if(num[i] == i+1)
            check++;
        else if(num[i] == j){
            check--;
            j--;
        }
    }
    
    if(check == 8)
        printf("ascending");
    else if(check == -8)
        printf("descending");
    else printf("mixed");

    return (0);
}