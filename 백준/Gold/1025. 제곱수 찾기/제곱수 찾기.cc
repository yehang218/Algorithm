#include <iostream>
#include <cmath>

using namespace std;

int N, M;
int num[10][10];

void input()
{
    char c;

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> c;
            num[i][j] = c - '0';
        }
    }
}

int solve()
{
    int answer = -1;
    int temp_i, temp_j;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // 각 행, 열의 등차 고정
            for(int index_n = -N; index_n<N; index_n++)
            {
                for(int index_m = -M; index_m<M; index_m++)
                {
                    if(index_n == 0 && index_m == 0) continue;

                    int number = 0;
                    temp_i = i; temp_j = j;
                    while(temp_i >= 0 && temp_i < N && temp_j >= 0 && temp_j < M)
                    {
                        number *= 10;
                        number += num[temp_i][temp_j];
                        temp_i += index_n;
                        temp_j += index_m;
                        // 제곱수라면
                        int temp = sqrt(number);
                        if(temp*temp == number) answer = max(answer, number);
                    }
                }
            }
        }
    }
    return answer;
}

int main(void)
{
    input();
    cout << solve();
}