#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
char map[51][51];
string map_B[8] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
string map_W[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};

int answer = 987654321;

int solve(int start, int end)
{
    int result_W = 0;
    int result_B = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (map[i + start][j + end] != map_B[i][j])
            {
                result_B++;
            }
            if (map[i + start][j + end] != map_W[i][j])
            {
                result_W++;
            }
        }
    }

    return min(result_B, result_W);
    ;
}

void input()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
}

int main(void)
{
    input();

    for (int i = 0; i < N - 8 + 1; i++)
    {
        for (int j = 0; j < M - 8 + 1; j++)
        {
            answer = min(answer, solve(i, j));
        }
    }
    cout << answer << "\n";
}