#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum[1001];

int main(void)
{
    int N;
    vector<int> v;
    int result = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            sum[i] = sum[i - 1] + v[i];
        else
            sum[i] = v[i];
        result = result + sum[i];
    }
    cout << result;
}