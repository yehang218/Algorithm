#include<stdio.h>

int main(void)
{
    int num[10] = {0};
    int mod[10] = {0};
    int check[10] = {0};
    int result = 0;

    for(int i = 0; i< 10;i++){
        scanf("%d", &num[i]);
    }
    for(int i=0;i<10;i++){   
        mod[i] = num[i] % 42;
    }
    
    for(int i =0; i< 10; i++)
    {
        for(int j = i + 1; j < 10; j++)
        {
            if(mod[i] == mod[j])
                check[i]++;
        }
    }

    for(int i = 0;i<10;i++)
    {
        if(check[i] == 0)
            result++;
    }
    printf("%d", result);
    return (0);
}