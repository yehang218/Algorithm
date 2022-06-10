#include<stdio.h>

int main(void)
{
    int A, B;
    double div = 0;
    scanf("%d %d", &A, &B);
    div = (double)A / (double)B;
    printf("%.20f",div);
}
