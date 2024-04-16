#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// 문제 분석
/*
1. recommend x
1-1. x = 1 : 문제 리스트에서 가장 어려운 문제 번호 출력 (여러개라면 문제 번호 ↑)
1-2. x = -1 : 문제 리스트에서 가장 쉬운 문제 번호 출력 (여러개라면 문제 번호 ↓)
=> 이때, 정렬을 계속 해야하므로 시간 복잡도가 굉장히 높아짐!
=> 이를 해결하기 위해 삽입이 되면, 자동으로 정렬해주는 set 자료구조 사용

2. add P L
2.1 문제 리스트에 난이도 L인 문제 번호 P 추가

3. solved P
3.1 문제 리스트에서 P 제거
*/

int N; // 문제 개수
int M; // 명령문의 개수
map<int, int> m_problem_list;

struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        // 같다면 문제 번호가 큰 것 출력
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};

set<pair<int, int>, cmp> s_problem_dict;

void solve(string command)
{
    int x, P, L = 0;

    if (command[0] == 'r')
    {
        cin >> x;

        if (x == 1)
        {
            cout << s_problem_dict.begin()->first << "\n";
        }
        else if (x == -1)
        {
            cout << s_problem_dict.rbegin()->first << "\n";
        }
    }

    else if (command[0] == 'a')
    {
        cin >> P >> L;
        m_problem_list.insert({P, L});
        s_problem_dict.insert({P, L});
    }

    else if (command[0] == 's')
    {
        cin >> P;
        s_problem_dict.erase({P, m_problem_list[P]});
    }
}

void input()
{
    int P, L;
    string command;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> P >> L;
        m_problem_list.insert({P, L});
        s_problem_dict.insert({P, L});
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> command;
        solve(command);
    }
}

int main(void)
{
    input();
}