// 현재 궁수가 공격할 수 있는 적 벡터 저장
// 적 위치 정렬(가까운순 -> 같으면 왼쪽부터) <- 아기 상어때처럼
// 현재 궁수가 공격할 적 또다른 벡터에 저장
// 모든 궁수에 대해서 반복
// 적 공격 시작(이때 잡은 적의 수 카운트(중복X))
// 적 내리지말고 궁수 올리기

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N; // 격자판 행의 수
int M; // 격자판 열의 수
int D; // 궁수의 곡역 거리 제한
int map[17][17];
int copy_map[17][17];

vector<pair<int, int>> v_archer_pos;

int die[17][17];
int result = 0;

typedef struct node
{
    int x;
    int y;
    int dis;
} node;

bool cmp(node n1, node n2)
{
    // 거리가 같으면
    if (n1.dis == n2.dis)
    {
        // 왼쪽부터
        return n1.y < n2.y;
    }
    return n1.dis < n2.dis;
}

int play();
void output()
{
    cout << "\n";
    cout << "\n";

    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << copy_map[i][j] << " ";
        }
        cout << "\n";
    }
}

void input()
{
    // 격자판 N*M
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
}

// 궁수 3명 배치(성이 있는 칸에만 / 1칸당 1명)
void archer_pos(int count_archer, int now)
{
    if (count_archer == 3)
    {
        memcpy(copy_map, map, sizeof(map));
        // cout << "result : " << result << "\n";
        result = max(result, play());
        return;
    }

    for (int i = now; i < M; i++)
    {
        if (map[N][i] == 2)
            continue;
        // 궁수 위치 저장
        v_archer_pos.push_back({N, i});
        archer_pos(count_archer + 1, i + 1);
        v_archer_pos.pop_back();
    }
}

int play()
{
    // 3명의 궁수가 잡은 적의 수
    int play_result = 0;
    // 모든 궁수의 위치
    int archerPos = N;

    while (archerPos >= 1)
    {
        // cout << "ap : " << archer_pos << "\n";
        vector<pair<int, int>> v_all_enemy_pos;
        // 모든 궁수에 대해서 반복
        for (auto a_archer_pos : v_archer_pos)
        {
            int x = archerPos;
            int y = a_archer_pos.second;

            vector<node> v_enemy;
            for (int j = 0; j < archerPos; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    // 현재 궁수가 공격할 수 있는 적 벡터 저장
                    // 적이 아니면 다음꺼 탐색
                    if (copy_map[j][k] == 0)
                        continue;

                    int distance = abs(x - j) + abs(y - k);

                    // 거리가 먼 적이면 패스
                    if (distance > D)
                        continue;

                    // 현재 궁수가 공격할 수 있는 적 벡터 저장
                    v_enemy.push_back({j, k, distance});
                }
            }

            // 공격할 수 있는 적이 없으면
            if (v_enemy.empty())
                continue;

            // 적 위치 정렬(가까운순 -> 같으면 왼쪽부터)
            sort(v_enemy.begin(), v_enemy.end(), cmp);
            v_all_enemy_pos.push_back({v_enemy[0].x, v_enemy[0].y});
        }

        int v_size = v_all_enemy_pos.size();
        // cout << v_size << "\n";
        for (int i = 0; i < v_size; i++)
        {
            int x = v_all_enemy_pos.back().first;
            int y = v_all_enemy_pos.back().second;

            // 적 공격 시작(이때 잡은 적의 수 카운트(중복X))
            if (copy_map[x][y] == 1)
            {
                copy_map[x][y] = 0;
                play_result++;
            }
            v_all_enemy_pos.pop_back();
        }

        // 적 내리지말고 궁수 올리기
        archerPos--;
    }

    return play_result;
}

int main(void)
{
    input();
    archer_pos(0, 0);
    cout << result;
}