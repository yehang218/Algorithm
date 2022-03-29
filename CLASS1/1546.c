#include<stdio.h>

int main(void)
{
    int N;
    int subject[1000];
    int max;
    int i;
    float avg = 0;

    scanf("%d",&N);
    for(i =0; i<N;i++)
        scanf("%d", &subject[i]);
    max = subject[0];
    for(i =0;i<N;i++)
        if(max < subject[i])
            max = subject[i];

    for(i = 0; i < N; i++)
        avg += (subject[i] / (float)max) * 100;
    avg = avg / N;
    printf("%.20lf",avg);
    return (0); 
}