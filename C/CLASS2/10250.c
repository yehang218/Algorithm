#include<stdio.h>

void print_room(int H, int W, int N)
{
    int guest = 1;
    for(int i = 1; i<=W; i++)
    {
        for(int j = 1; j<=H; j++)
        {
            if(guest == N ){
                if(i < 10)
                    printf("%d0%d\n",j,i);
                else
                    printf("%d%d\n",j,i);
                return;
            }
            guest++;
        }
    }
    return;
}

int main(void)
{
    int T;
    int H, W, N;

    scanf("%d", &T);
    for(int i = 0; i< T ; i++)
    {
        scanf("%d %d %d", &H ,&W ,&N);
        print_room(H, W, N);
    }
    return (0);
}