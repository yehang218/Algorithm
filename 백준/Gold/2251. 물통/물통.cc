#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int A, B, C;
int visit[201][201][201];

struct node
{
    int a;
    int b;
    int c;
};
queue<node> q;
vector<int> v_result;

void input()
{
    cin >> A >> B >> C;
}

void bfs()
{
    q.push({0, 0, C});

    while (!q.empty())
    {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        if (visit[a][b][c] != 0)
            continue;
        visit[a][b][c]++;

        if (a == 0)
            v_result.push_back(c);

        // A -> B
        if (a + b > B)
            q.push({a + b - B, B, c});
        else
            q.push({0, a + b, c});

        // A -> C
        if (a + c > C)
            q.push({a + c - C, b, C});
        else
            q.push({0, b, a + c});

        // B -> A
        if (b + a > A)
            q.push({A, b + a - A, c});
        else
            q.push({b + a, 0, c});

        // B -> C
        if (b + c > C)
            q.push({a, b + c - C, C});
        else
            q.push({a, 0, b + c});

        // C -> A
        if (c + a > A)
            q.push({A, b, c + a - A});
        else
            q.push({c + a, b, 0});

        // C -> B
        if (c + b > B)
            q.push({a, B, c + b - B});
        else
            q.push({a, b + c, 0});
    }

    sort(v_result.begin(), v_result.end());
    for (int i = 0; i < v_result.size(); i++)
    {
        cout << v_result[i] << " ";
    }
}

int main(void)
{
    input();
    bfs();
}