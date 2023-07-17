#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int degree[32002];
vector<int> v[100001];
priority_queue<int, vector<int>, greater<int>> pq;

void input()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        v[A].push_back(B);
        degree[B]++;
    }
}

void topology()
{
    for (int i = 1; i <= N; i++)
    {
        if (degree[i] == 0)
            pq.push(i); // 진입 차수가 0인 수 삽입(예제 : 3, 4)
    }

    while (!pq.empty())
    {
        int x = pq.top(); // 3 // 1 // ..
        pq.pop();         // 4 // 다시 4 // ..
        cout << x << " "; // 3 // 3 1 // ..

        for (int i = 0; i < v[x].size(); i++) // 3과 연결된 애들 // 1과 연결된 애들 없음 //..
        {
            int y = v[x][i]; // 3과 연결된 애들 => 1 //  //..
            degree[y]--;     // 1의 간선 줄이기 // //..

            if (degree[y] == 0) // 1 삽입 // // ..
                pq.push(y);     // 4, 1 // // ..
        }
    }
}

int main(void)
{
    input();
    topology();
}