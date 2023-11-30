#include <iostream>

using namespace std;

void solve(int start, int by, int end, int N)
{
    // answer++;
    if (N == 1)
    {
        cout << start << " " << end << "\n";
        return;
    }

    // 1번 장대에 있는 N-1개 원판을 3번 장대를 거쳐 2번 장대로 옮기기
    solve(start, end, by, N - 1);
    // 1번 장대에 있는 원판 3번으로 옮기기
    cout << start << " " << end << "\n";
    // 2번 장대에 있는 N-1개 원판 1번 장대를 거쳐 3번 장대로 옮기기
    solve(by, start, end, N - 1);
}

int hanoi_count(int N)
{
    int answer = 1;
    while (N > 1)
    {
        answer = answer * 2 + 1;
        N--;
    }
    return answer;
}

int main(void)
{
    int N;
    cin >> N;
    cout << hanoi_count(N) << "\n";
    solve(1, 2, 3, N);
    // cout << answer;
}