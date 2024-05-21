// 문제 분석
/*
 1. 제목이 입력값으로 들어옴
 2. 가장 많이 팔린 책의 제목은??

 -> Map에 키 = 이름, 값 = 개수 로 저장한다.
 -> 이때, 맵은 value를 기준으로 정렬하지 못하기 때문에, vector로 이동한 후에 정렬한다!
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 오늘 하루동안 팔린 책의 개수 (1 <= N <= 1000)
map<string, int> m_book;

bool compare(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

void input()
{
    string str;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        m_book[str]++;
    }
}

void solve()
{
    vector<pair<string, int>> v_book(m_book.begin(), m_book.end());
    sort(v_book.begin(), v_book.end(), compare);

    cout << v_book.front().first;
}

int main(void)
{
    input();
    solve();
}