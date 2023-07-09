#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K, X;

vector<int> city[1000001];
queue<int> check;
vector<int> result;

int visited[300001];

int main(void)
{
    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++)
    {
        int start;
        int end;
        cin >> start >> end;
        city[start].push_back(end);
    }

    check.push(X);
    visited[X]++;

    while (!check.empty())
    {
        int x = check.front(); // 현재 큐 맨 아래 있는 숫자 x에 저장
        check.pop();           // 큐에서 빼기

        for (int i = 0; i < city[x].size(); i++)
        {
            int y = city[x][i];  // 이어지는 도시 번호 y에 저장
            if (visited[y] == 0) // 방문한 적이 있었는지 확인(없었다면)
            {
                check.push(y);               // 큐에 도시 넣기
                visited[y] = visited[x] + 1; // 현재 위치보다 거리 1 늘리기
            }
        }
    }

    for (int i = 1; i < N + 1; i++) // 최단 거리가 K와 같으면 result에 넣기
    {
        if (visited[i] - 1 == K)
            result.push_back(i);
    }

    if (result.empty()) // 최단 거리가 K인 도시가 하나도 존재하지 않으면 -1 출력
        cout << "-1";
    else
    {
        for (int i = 0; i < result.size(); i++) // 있으면 도시 숫자 출력
            cout << result.at(i) << "\n";
    }
}