#include<iostream>
using namespace std;

int main(void)
{
    int N;
    int arr[101] = {0};
    int x;
    int cnt = 0;

    cin >> N;

    for(int i = 0; i<N; i++)
    {
        cin >> arr[i];
    }

    cin >> x;

    for(int i = 0; i<N; i++)
    {
        if(x == arr[i]) cnt++;
    }
    cout << cnt;
}