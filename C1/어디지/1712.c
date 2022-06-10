#include<stdio.h>

int main(void)
{
    int A, B, C;
    long long AmCmB = 0;
    int i = 0;
    
    scanf("%d %d %d", &A, &B, &C);

    if(C - B <= 0)
    {
        printf("-1");
        return (0);
    }
    AmCmB = A / (C - B);

    while(1)
    {
        if(i > AmCmB){
            printf("%d" , i);
            return (0);
        }
        i++;
    }
    return (0);
}