#include<stdio.h>

int main(void)
{
    int A, B, V;
    int day = 0;

    scanf("%d %d %d", &A, &B, &V);

    day = (V-B) / (A-B);
    if((V-B) % (A-B) != 0)
        day++;
    printf("%d", day);

    return (0);
}