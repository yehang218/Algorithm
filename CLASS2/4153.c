#include<stdio.h>

int check_square(int x1, int x2, int x3)
{
    if(x1 * x1 == (x2 * x2) + (x3 * x3))
        return 1;
    else if(x2 * x2 == (x1 * x1) + (x3 * x3))
        return 1;
    else if(x3 * x3 == (x1 * x1) + (x2 * x2))
        return 1;
    else return 0;
}

int main(void)
{
    int x1, x2, x3;

    while(1)
    {
        scanf("%d %d %d", &x1, &x2, &x3);

        if(x1 == 0 && x2 == 0 && x3 == 0)
            return 0;

        if(check_square(x1,x2,x3))
            printf("right\n");
        else 
            printf("wrong\n");
    }

    return (0);
}