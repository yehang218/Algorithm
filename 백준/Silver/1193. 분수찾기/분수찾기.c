#include<stdio.h>

int main(void)
{
    int X, j = 1;
    int plus = 1;
    int last = 1;

    scanf("%d", &X);
    while(last<X){
        plus++; 
        last = last + plus;
    }
    
    last = last - plus;
    for(int i = plus; i>=1; i--)
    {  
        if(j ==X -last ){
            if(plus%2)
                printf("%d/%d", i ,j);
            else
                printf("%d/%d", j, i);
            return 0;
        }
        j++;
    }

    return 0;
}