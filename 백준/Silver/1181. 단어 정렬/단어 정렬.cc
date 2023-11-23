#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string &x, string &y)
{
    // 길이가 같으면 사전순
    if (x.length() == y.length())
    {
        return x < y;
    }

    else
    {
        // 길이가 작은 순으로 정렬
        return x.length() < y.length();
    }
}

void solve(int N)
{
    vector<string> v_str;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        v_str.push_back(str);
    }

    // 조건에 맞춰 정렬
    sort(v_str.begin(), v_str.end(), compare);

    // 중복 제거
    v_str.erase(unique(v_str.begin(), v_str.end()), v_str.end());

    // 정답 출력
    for (int i = 0; i < v_str.size(); i++)
    {
        cout << v_str[i] << "\n";
    }

    return;
}

int main(void)
{
    int N;
    cin >> N;

    solve(N);

    return 0;
}