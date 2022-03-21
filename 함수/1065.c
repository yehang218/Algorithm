#include<stdio.h>

int check_as(int n)
{
    int ten[4] = {0};
    int i, j;
    int check[4] = {0};

    for(i = 0; n > 0; i++)
    {
        ten[i] = n % 10;
        n = n / 10;
    }

    for(j = 0; j < i - 1; j++)
    {
        check[j] = ten[j] - ten[j + 1];
        if(j > 0  && check[j] != check[j-1])
            return 1;
    }
    return 0;
}

int main(void)
{
    int N;
    int check = 0;
    
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        if(!check_as(i))
            check++;
    }
    printf("%d", check);
    return 0;
}