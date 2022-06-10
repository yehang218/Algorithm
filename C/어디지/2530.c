#include<stdio.h>

int main(void)
{
    int A, B, C, D;

    scanf("%d %d %d", &A, &B, &C);
    scanf("%d", &D);

    C = C + D;
    if(C >= 60){
        B = B + (C / 60);
        C = C % 60;
    }
    if(B >= 60){
        A = A + (B / 60);
        B = B % 60;
    }
    if(A > 23){
        A = A % 24;  
    }
    printf("%d %d %d", A, B, C);

    return (0);
}