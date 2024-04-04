#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int maxNumber = 0;
vector<int> relation[10001];
vector<pair<int, int>> answer;

void input()
{
    int a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        relation[b].push_back(a);
    }
}

void bfs(int a)
{
    queue<int> q;
    int count = 0;
    bool check[10001] = {0, };

    q.push(a);
    check[a] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0; i < relation[x].size(); i++)
        {
            int y = relation[x][i];
            if (check[y])
                continue;
            check[y] = true;
            q.push(y);
            count++;
        }
    }

    answer.push_back({a, count});
    maxNumber = max(maxNumber, count);
}

int main(void)
{
    input();

    for (int i = 1; i <= N; i++)
    {
        bfs(i);
    }

    for (int i = 0; i < N; i++)
    {
        if (maxNumber == answer[i].second)
            cout << answer[i].first << " ";
    }
}