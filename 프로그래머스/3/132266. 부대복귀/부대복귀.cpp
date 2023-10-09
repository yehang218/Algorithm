#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[100001];
vector<int> road[100001];
int copy_n;

void init()
{
    for(int i = 1; i < copy_n + 1; i++)
    {
        visit[i] = 0;
    }
}

int bfs(int start, int end)
{
    init();
    queue<int> q;
    
    q.push(start);
    visit[start]++;
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        
        if(x == end) return visit[x] - 1;

        for(int i = 0; i < road[x].size(); i++)
        {
            int nx = road[x][i];
            
            if(visit[nx] != 0) continue;
            
            visit[nx] = visit[x] + 1;
            q.push(nx);
        }
    }
    
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    copy_n = n;
    
    for(int i = 0; i<roads.size(); i++)
    {
        int x = roads[i][0];
        int y = roads[i][1];
        
        road[x].push_back(y);
        road[y].push_back(x);
    }
    
    for(int i = 0; i<sources.size(); i++)
    {
        int ans = bfs(sources[i], destination);
        answer.push_back(ans);
    }
    
    
    
    return answer;
}
