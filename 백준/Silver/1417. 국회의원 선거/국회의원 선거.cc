#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int>> pq; // 내림차순 우선순위 큐

int N;
int No1;    // 다솜이의 득표 수
int result; // 매수한 표 수

void input()
{
    cin >> N;
    cin >> No1;

    for (int i = 0; i < N - 1; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }
}

void cal()
{
    while (!pq.empty() && pq.top() >= No1)
    {
        int top = pq.top();
        pq.pop();
        top--;
        pq.push(top);

        No1++;
        result++;
    }
}

int main(void)
{
    input();
    cal();

    cout << result << "\n";
}