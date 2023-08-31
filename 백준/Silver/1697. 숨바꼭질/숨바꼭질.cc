// 수빈이 -> X+1, X-1, 2X

#include <iostream>
#include <queue>

using namespace std;

int N; // 수빈이가 있는 위치
int K; // 동생이 있는 위치

int move_x[3] = {1, -1, 2};
int visit[200002];

void input()
{
    cin >> N >> K;
}

void bfs()
{
    queue<int> q;

    q.push(N);
    visit[N]++;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < 3; i++)
        {
            int nx;
            if (i == 2)
                nx = x * move_x[i];
            else
                nx = x + move_x[i];

            if (nx < 0 || nx > 200000)
                continue;

            if (visit[nx] != 0)
                continue;
            if (nx == K)
            {
                cout << visit[x]; // visit[N]이 1부터 시작해서 +1을 안해줘도됨
                return;
            }
            visit[nx] = visit[x] + 1;
            q.push(nx);
        }
    }
}

int main(void)
{
    input();
    if (N == K)
    {
        cout << "0";
        return 0;
    }
    bfs();
}