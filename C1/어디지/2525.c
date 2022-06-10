#include<stdio.h>

int main(void)
{
    int A, B, C;

    scanf("%d %d", &A, &B);
    scanf("%d", &C);

    A = A + (C / 60);
    B = B + (C % 60);
    if(B >= 60)
    {
        B = B - 60;
        A++;
    }   
    if(A >= 24)
        A = A -24;
    printf("%d %d", A, B);
    return (0);
}