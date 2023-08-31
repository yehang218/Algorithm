#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[1001];         // 컴퓨터의 부모 담길 배열
int result_cost = 0; // 필요한 비용

int N, M;

typedef struct node
{
    int pa; // 부모
    int ca; // 자식
    int cost;
} node;

vector<node> v;

int compare(node n1, node n2)
{
    return n1.cost < n2.cost;
}

int Find(int now)
{
    if (p[now] == now)
        return now;
    return p[now] = Find(p[now]);
}

void Union(int pa, int pb)
{
    p[pa] = pb;
}

void input()
{
    int a, b, c;
    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; i++)
        p[i] = i;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
}

void msp()
{
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
    {
        int pa = v[i].pa;
        int ca = v[i].ca;

        Find(ca);
        Find(pa);

        if (p[ca] != p[pa])
        {
            Union(p[pa], p[ca]);
            // cout << v[i].cost << " ";
            result_cost = result_cost + v[i].cost;
        }
        else
            continue;
    }
}

int main(void)
{
    input();
    msp();
    cout << result_cost;
}