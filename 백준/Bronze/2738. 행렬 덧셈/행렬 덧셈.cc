#include<iostream>
using namespace std;

int main(void)
{
    int N, M;
    int A[100][100] = {0};
    int B[100][100] = {0};
    int sum[100][100] = {0};

    cin >> N >> M;

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i<N; i++)
    {
        for(int j = 0; j<M; j++)
        {
            cin >> B[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0;j<M; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
}