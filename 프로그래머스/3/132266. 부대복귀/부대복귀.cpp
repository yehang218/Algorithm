
#include<queue>
#include <string>
#include <vector>

using namespace std;

int visit[100001];
int copy_n;

void init()
{
    for(int i = 0; i < copy_n; i++)
    {
        visit[i] = 0;
    }
}

int bfs(int start, int end, vector<vector<int>> roads)
{  
    init();
    queue<int> q;
    
    q.push(start);
    visit[start]++;
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        
        if(x == end) return visit[x];
        
        for(int i = 0; i < roads[x].size(); i++)
        {
            int nx = roads[x][i];
            
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
    
    for(int i = 0; i < sources.size(); i++)
    {
        int ans = bfs(sources[i], destination, roads);
        answer.push_back(ans);
    }
    return answer;
}
