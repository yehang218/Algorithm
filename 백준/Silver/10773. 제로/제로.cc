#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int K, answer = 0;
    ;
    cin >> K;

    int num;
    stack<int> s_num;
    for (int i = 0; i < K; i++)
    {
        cin >> num;
        if (num == 0)
        {
            answer -= s_num.top();
            s_num.pop();
        }
        else
        {
            answer += num;
            s_num.push(num);
        }
    }

    cout << answer;
}