// 치킨 거리 : 집과 가자 가까운 치킨집 사이의 거리
// 도시의 치킨 거리 : 모든 집의 치킨 거리의 합
// 0은 빈칸 / 1은 집 / 2는 치킨 집
// M개의 치킨집만 생존 나머지 폐업 -> 도시의 치킨 거리가 가장 작게 되는 경우?

// 치킨집 하나씩 없애보기
// 집을 기준으로 치킨집 사이의 거리 찾기

// 0. input 받으면서 집 벡터, 치킨집 벡터에 저장
// 1. 재귀 사용해서 치킨집 폐업시키기(폐업시킨건 visit으로 확인) -> 모두 폐업 시켰으면
// 2. 폐업안된 치킨집들이랑 집까지 거리구하기

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
int map[55][55]; // 도시의 정보
int result_min = 987654321;
int all_chicken_count = 0;

int visit[15];

typedef struct node
{
    int x;
    int y;
} node;

vector<node> v_house;
vector<node> v_chicken;
vector<node> v_survive_chicken;

void find_dis();

void input()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
            {
                v_house.push_back({i, j});
            }
            else if (map[i][j] == 2)
            {
                v_chicken.push_back({i, j});
                all_chicken_count++;
            }
        }
    }
}

// 1. 재귀 사용해서 치킨집 폐업시키기(폐업시킨건 visit으로 확인) -> 모두 폐업 시켰으면
void find_chicken_pos(int count_chicken, int now)
{
    if (count_chicken == M)
    {
        find_dis();
        return;
    }

    for (int i = now; i < all_chicken_count; i++)
    {
        if (visit[i] == 1)
            continue;

        visit[i] = 1;
        v_survive_chicken.push_back({v_chicken[i].x, v_chicken[i].y});
        find_chicken_pos(count_chicken + 1, i + 1);
        visit[i] = 0;
        v_survive_chicken.pop_back();
    }
}

// 2. 폐업안된 치킨집들이랑 집까지 거리구하기
// 집을 기준으로 치킨집 사이의 거리 찾기
void find_dis()
{
    int sum_dis = 0;
    for (int i = 0; i < v_house.size(); i++)
    {
        int min_dis_one = 987654321;
        int hx = v_house[i].x;
        int hy = v_house[i].y;

        for (int j = 0; j < v_survive_chicken.size(); j++)
        {
            int cx = v_survive_chicken[j].x;
            int cy = v_survive_chicken[j].y;

            int dis = abs(hx - cx) + abs(hy - cy);
            min_dis_one = min(min_dis_one, dis);
        }
        sum_dis += min_dis_one;
    }
    result_min = min(result_min, sum_dis);
}

int main(void)
{
    input();
    find_chicken_pos(0, 0);
    cout << result_min;
}