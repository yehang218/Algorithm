#include<stdio.h>

int main(void)
{
    int H, M;

    scanf("%d %d", &H, &M);

    M = M - 45;
    if(M < 0)
    {
        if(H == 0)
            H = 24;
        H--;
        M = 60 + M;
    }
    printf("%d %d", H, M);
    return (0);
}