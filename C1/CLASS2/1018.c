#include<stdio.h>

int main(void){
    int N, M;
    char Chess[51][51];

    scanf("%d %d", &N, &M);
    for(int i = 0; i <N; i++){
        for(int j = 0; j < M; j++)
        {
            scanf(" %c", Chess[i][j]);
        }
    }
}