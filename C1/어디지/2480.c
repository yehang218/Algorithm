#include<stdio.h>

int find_max(int dice1, int dice2, int dice3)
{
    int max = dice1;

    if(dice2 > max)
    {
        max = dice2;
        if(dice3 > max)
            max = dice3;
    }
    else if(dice3 > max)
        max = dice3;

    return max;
}

int main(void)
{
    int dice1, dice2, dice3;
    int reward = 0;

    scanf("%d %d %d", &dice1, &dice2, &dice3);

    if (dice1 == dice2 && dice2 == dice3)
        reward = 10000 + (dice1 * 1000);
    else if (dice1 == dice2)
        reward = 1000 + (dice1 * 100);
    else if (dice1 == dice3)
        reward = 1000 + (dice1 * 100);
    else if (dice2 == dice3)
        reward = 1000 + (dice2 * 100);
    else
        reward = find_max(dice1,dice2, dice3) * 100;
    printf("%d", reward);
    return (0);
}