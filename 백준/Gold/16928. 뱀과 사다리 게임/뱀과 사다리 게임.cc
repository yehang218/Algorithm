#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N; // 사다리의 수
int M; // 뱀의 수

int ladder[102]; // 사다리
int snake[102];  // 뱀

queue<int> player;

int dice[6] = {1, 2, 3, 4, 5, 6};
int map[102];

void input()
{
    int x, y; // 사다리의 정보(x -> y)
    int u, v; // 뱀의 정보(u -> v)

    cin >> N >> M; // 사다리의 수
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        ladder[x] = y;
    }

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        snake[u] = v;
    }

    memset(map, 0, sizeof(map));
}

void move_map()
{
    player.push(1);
    map[1] = 1;

    while (!player.empty())
    {
        int pos = player.front();
        player.pop();

        for (int i = 0; i < 6; i++)
        {
            int des = pos + dice[i];
            if (des > 100)
                continue;

            if (ladder[des] != 0) // 사다리가 이어진 경우
            {
                des = ladder[des];
            }
            else if (snake[des] != 0)
            {
                des = snake[des];
            }

            if (map[des] != 0)
            {
                continue;
            }

            player.push(des);
            map[des] = map[pos] + 1;
            if (des == 100)
            {
                cout << map[des] - 1 << "\n";
                return;
            }
        }
    }
}

int main(void)
{
    input();
    move_map();
}