#include<stdio.h>

int main(void)
{
    int num[6];
    int i = 0;
    int result = 0;

    for(i = 0; i< 5; i++){
        scanf("%d", &num[i]);
        result += num[i] * num[i];
    }
    printf("%d", result % 10);
    return (0);
}