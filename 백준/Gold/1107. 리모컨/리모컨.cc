// 1. 100-n 절댓값 구하기 (0이면 더 보지도 않고 끝내기!)
// 2. 자리수 + 누르는 횟수 구하기
// 2-1. 이때, 불가 버튼이 포함되어 있으면 구하지 않고 넘어가기
// 3. 최소수 갱신!

#define INF 987654321

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;                   // 이동하려고 하는 채널
int M;                   // 고장난 버튼의 개수
vector<char> broken_btn; // 고장난 버튼 배열

// 1. 100 - n 절댓값 구하기
int minus_abs()
{
    int n = 100 - N;
    n = abs(n);
    return n;
}

// 자릿수 구하기 + 누르는 횟수
int check_digit_press_time(int n)
{
    int check_time = 0;
    int digit = 0;
    int check_broken = 0;

    string str_n = to_string(n);

    for (int i = 0; i < broken_btn.size(); i++)
    {
        // 문자가 있으면
        if (str_n.find(broken_btn[i]) != string::npos)
        {
            check_broken++;
        }
    }

    if (check_broken != 0)
        return INF;

    // 자릿수 구하기
    digit = str_n.length();

    // 누르는 횟수
    check_time = abs(N - n);

    check_time = check_time + digit;

    return check_time;
}

int solve()
{
    int min_result = INF;
    int abs_num = minus_abs();

    // 0이면 보지도 않고 끝내기
    if (abs_num == 0)
        return 0;
    else
        min_result = abs_num;

    for (int i = 0; i <= 1000000; i++)
    {
        int check_time = check_digit_press_time(i);
        min_result = min(min_result, check_time);
    }

    return min_result;
}

int main(void)
{
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        char c;
        cin >> c;
        broken_btn.push_back(c);
    }

    cout << solve();
}