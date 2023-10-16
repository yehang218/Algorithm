#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 회전 초밥 벨트에 놓인 접시의 수
int d; // 초밥의 가짓수
int k; // 연속해서 먹는 접시의 수
int c; // 쿠폰 번호

vector<int> sushi;

int sushi_type[3001];
int type_num; // 초밥 종류
void input()
{
    int x;

    cin >> N >> d >> k >> c;

    sushi_type[c] = 1;
    type_num++;

    for(int i = 0; i < N; i++)
    {
        cin >> x;
        sushi.push_back(x);

        if(i < k)
        {
            sushi_type[x]++;
            if(sushi_type[x] == 1) type_num++;
        }
    }
}

void solve()
{
    int left = 0;
    int right = k - 1;
    int result = 0;

    for(int i = 0; i < k; i++)
    {
        sushi.push_back(sushi[i]);
    }

    while(true)
    {
        result = max(result, type_num);
        if(left == N) break;
        sushi_type[sushi[left]]--;
        if(sushi_type[sushi[left++]] == 0) type_num--;
        sushi_type[sushi[++right]]++;
        if( sushi_type[sushi[right]] == 1) type_num++;
    }
    cout << result;
}

int main(void)
{
    input();
    solve();
}