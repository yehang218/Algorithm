// 극 다름 -> 반대 방향으로 회전 / 극 같음 -> 회전 X
// 12시부터 시계방향 순으로 상태 주어짐 / N극은 0, S극은 1
// 1인경우 시계방향, -1인 경우 반시계 방향

// 톱니바퀴라 돌아갈텐데 마지막 인덱스에 도착하면 그 다음껀 처음으로 보내야하지 않을까

// K만큼 회전하는데 시작은 rotation_num에 있는 친구부터. rotation_dir로 방향체크
// 맞닿은 친구들은 gear[0][2], gear[1][6]/ gear[1][2], gear[2][6]/ gear[2][2], gear[3][6]

// for문 k만큼 돌리면서 rotation_num[i]-1에 있는 친구부터 확인
// 1 -> 2->3->4 / 2->1&2->3->4 / 3->2->1 & 3->4 / 4->3->2->1
// 영향을 주는애들은 확실함 1이랑 2랑 만약 3부터 시작이면 1보다 2가 먼저임
// 즉, rotation_num-i 했을 때 작은 애들부터

// 가까운 애들부터 점점 돌아야함 -> 이거 아님...ㅠ

// dis[] = 2, 1, 0 ,1
// 맞닿은 친구들 값 미리 저장
// 돌아가는 방향만 저장해두고 for문으로 한꺼번에 돌아가게 처리하면 될듯
// -> 기준에서 왼쪽을 비교하면 그 다음 가까운 톱니도 왼쪽밖에 비교 못함(오른쪽은 기준이라 이미 했으니까)
// -> 기준에서 오른쪽 비교하면 그 다음 가까운 톱니도 오른쪽밖에 비교 못함

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int K;                                                                               // 총 회전하는 횟수
vector<int> gear[4];                                                                 // 톱니바퀴 상태
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dis; // 기준으로부터 거리
int rotation_num[101];                                                               // 회전시킨 톱니바퀴 번호
int rotation_dir[101];                                                               // 회전시킨 방향

void calc_rank(int start);
vector<int> rotation_clockwise(vector<int> gear);
vector<int> rotation_anticlockwise(vector<int> gear);
void output()
{
    cout << "\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << gear[i][j] << " ";
        }
        cout << "\n";
    }
}

void input()
{
    // 톱니바퀴 상태
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char c;
            cin >> c;
            gear[i].push_back(c - '0');
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> rotation_num[i] >> rotation_dir[i];
    }
}

void solve()
{
    int rotation_dir_r = 0;
    int roation_dir_now_l = 0;

    for (int i = 0; i < K; i++)
    {
        int roatation_dir_gear[4] = {
            0,
        };
        bool dir_check_ok[4] = {false, false, false, false};

        rotation_dir_r = rotation_dir[i];
        roation_dir_now_l = rotation_dir[i];
        roatation_dir_gear[rotation_num[i] - 1] = rotation_dir[i];
        dir_check_ok[rotation_num[i] - 1] = true;

        // 출발하는 기어부터의 거리 찾아서 작은 순으로 pq에 넣기
        calc_rank(rotation_num[i] - 1);

        // 미리 돌아갈 방향 세팅
        for (int j = 0; j < 4; j++)
        {
            // dis가 제일 작은애부터 확인
            int start_dis = dis.top().first; // 처음 시작한 기어까지의 거리
            int gear_num = dis.top().second; // 기어 숫자
            dis.pop();

            // 만약 맞닿은 친구들이 같다면 roatation_dir_gear 0으로 설정
            // 그렇지 않다면 반대 방향으로 설정
            if (gear_num < 3)
            {
                if (!dir_check_ok[gear_num + 1])
                {
                    // 기준의 오른쪽 비교 -> 같으면 안돔
                    if (gear[gear_num][2] == gear[gear_num + 1][6])
                    {
                        rotation_dir_r = 0;
                    }
                    else // 다르면 기준의 오른쪽에 반대 방향 저장
                        rotation_dir_r = rotation_dir_r * -1;

                    roatation_dir_gear[gear_num + 1] = rotation_dir_r;
                    dir_check_ok[gear_num + 1] = true; // 다음에 또 판단하면 안되니까 체크하기
                }
            }

            if (gear_num > 0)
            {
                if (!dir_check_ok[gear_num - 1])
                {
                    // 기준의 왼쪽 비교 -> 같으면 안돔
                    if (gear[gear_num][6] == gear[gear_num - 1][2])
                    {
                        roation_dir_now_l = 0;
                    }
                    else // 다르면 기준의 왼쪽에 반대 방향 저장
                        roation_dir_now_l = roation_dir_now_l * -1;

                    roatation_dir_gear[gear_num - 1] = roation_dir_now_l;
                    dir_check_ok[gear_num - 1] = true;
                }
            }
        }

        for (int j = 0; j < 4; j++)
        {
            // 반시계 회전
            if (roatation_dir_gear[j] == -1)
            {
                gear[j] = rotation_anticlockwise(gear[j]);
            }
            // 시계 회전
            if (roatation_dir_gear[j] == 1)
            {
                gear[j] = rotation_clockwise(gear[j]);
            }
        }
    }
}

void calc_rank(int start)
{
    for (int j = 0; j < 4; j++)
    {
        int n = start - j;
        if (n < 0)
            n = -n;
        dis.push({n, j}); // 거리, 기어 숫자
    }
}

// 시계 방향으로 회전
vector<int> rotation_clockwise(vector<int> gear)
{
    vector<int> result_gear;

    // 끝 값을 새로운 벡터의 첫값으로 넣고
    int last = gear[7];
    result_gear.push_back(last);

    // 나머지 값들은 그 뒤로 넣기
    for (int i = 0; i < 7; i++)
    {
        result_gear.push_back(gear[i]);
    }

    return result_gear;
}

// 반시계 방향으로 회전
vector<int> rotation_anticlockwise(vector<int> gear)
{
    vector<int> result_gear;

    // 두번째 값부터 새로운 벡터에 넣기
    for (int i = 1; i < 8; i++)
    {
        result_gear.push_back(gear[i]);
    }

    // 첫 값을 새로운 벡터의 끝 값으로 넣기
    int last = gear[0];
    result_gear.push_back(last);

    return result_gear;
}

int main(void)
{
    int result = 0;
    int two = 1;
    input();
    solve();

    for (int i = 0; i < 4; i++)
    {
        result = result + gear[i][0] * two;
        two = two * 2;
    }
    cout << result << "\n";
}