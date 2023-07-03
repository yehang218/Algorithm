#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
int check[9];

// 앞 수 이상인 수가 나와야하므로 now 사용
void solve(int index, int now)
{
    if (index == M)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = now; i <= N; i++) // 같은 수가 나와도 괜찮으므로 now + 1 아니고 now부터
    {
        v.push_back(i);
        solve(index + 1, i);
        v.pop_back();
    }
}

int main(void)
{
    cin >> N >> M;

    solve(0, 1);
}