#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void find(int N)
{
    vector<int> arr;
    int num = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());

    cout << arr.front() << " " << arr.back() << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, N;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        find(N);
    }
}