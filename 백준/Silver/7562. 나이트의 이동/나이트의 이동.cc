#include <iostream>
#include <queue>

using namespace std;

int n;
int I; // 한 변의 길이

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

class point
{
public:
    int x;
    int y;
};

void bfs(point p_start, point p_end)
{
    int check[301][301] = {
        0,
    };
    queue<point> q;

    q.push(p_start);
    check[p_start.x][p_start.y]++;

    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        if (x == p_end.x && y == p_end.y)
        {
            cout << check[x][y] - 1 << "\n";
            return;
        }

        for (int i = 0; i < 8; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];

            // 체스판 범위 밖인 경우
            if (cx >= I || cy >= I)
                continue;
            if (cx < 0 || cy < 0)
                continue;

            if (check[cx][cy] == 0)
            {
                point cal;
                check[cx][cy] = check[x][y] + 1;

                cal.x = cx;
                cal.y = cy;
                q.push(cal);
            }
        }
    }
}

int main(void)
{
    point p_start;
    point p_end;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> I;
        cin >> p_start.x >> p_start.y;
        cin >> p_end.x >> p_end.y;

        bfs(p_start, p_end);
    }
}