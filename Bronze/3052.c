#include<stdio.h>

int main(void)
{
    int num[10] = {0};
    int mod[10] = {0};

    for(int i = 0; i< 10;i++){
        scanf("%d", &num[i]);
    }
    for(int i=0;i<10;i++){   
        mod[i] = num[i] % 42;
    }
    
}