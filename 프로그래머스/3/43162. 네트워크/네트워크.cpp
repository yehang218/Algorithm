#include <string>
#include <queue>
#include <vector>

using namespace std;

int visit[201];
queue<int> q;
vector<int> v[201];


void bfs(int x)
{
    q.push(x);
    visit[x]++;
    
    while(!q.empty())
    {
            int x = q.front();
            q.pop();
            
            for(int i = 0; i < v[x].size(); i++)
            {
                int nx = v[x][i];
                if(visit[nx] != 0) continue;
                q.push(nx);
                visit[nx] = visit[x] + 1;
            }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    // 컴퓨터 연결상태 저장
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < computers[i].size(); j++)
        {
            if(computers[i][j] == 1 && i != j)
            {
                v[i].push_back(j);
            }
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < computers[i].size(); j++)
        {
            if(visit[i] == 0 && computers[i][j] == 1)
            {
                bfs(i);
                answer++;
            }
        }
    }
    
    return answer;
}
