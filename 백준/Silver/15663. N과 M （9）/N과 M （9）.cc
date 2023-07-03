#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
vector<int> v_N;

int check[9];
// int last;
// 전역변수로 선언되어 있으면 7 9를 출력했을 때 last 값이 9인 상태로 함수를 빠져나옴
// 그래서 last == v_N[i]에 걸려버려서 continue됨
// 즉, 9 9와 같이 index가 다르지만 같은 값을 가지는 수열은 출력하지 않음 (다른 index들과도 공유하는 last값)
void solve(int index)
{
    if (index == M)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    int last = 0; // 지역변수로 선언한 경우에는 7 9를 출력하고 함수를 빠져나오고 9를 확인할 때, 새로운 last값이 생김 last = 0
    // 즉, 같은 index끼리만 공유하는 last값을 가짐
    for (int i = 0; i < v_N.size(); i++)
    {
        // cout << "last : " << last << "\n";
        if (check[i] == 1 || last == v_N[i])
            continue;
        /*if (i != 0 && v_N[i] == v_N[i - 1])
            continue;*/
        check[i] = 1;
        v.push_back(v_N[i]);
        last = v_N[i];
        solve(index + 1);

        v.pop_back();
        check[i] = 0;
    }
}

int main(void)
{
    int num = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v_N.push_back(num);
    }
    sort(v_N.begin(), v_N.end());
    solve(0);
}