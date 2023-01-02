#include<iostream>
using namespace std;

int main(void)
{
    long long N, M;

    cin >> N >> M;
    if(N > M)
        cout << N - M;
    else cout << M - N;
}