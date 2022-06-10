#include<stdio.h>

int main(void)
{
    long long n, m;
    int mod;

    scanf("%d %d", &n, &m);

    mod = n % m;
    printf("%d\n%d\n", n/m, mod);
    return (0);
}