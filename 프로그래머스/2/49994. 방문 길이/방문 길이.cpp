#include <string>
using namespace std;

bool visit[11][11][4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int solution(string dirs) {
    int answer = 0;

    // 원점을 5,5 라고 생각
    int x = 5;
    int y = 5;

    int road = 0;
    int next_road = 0;

    for(int i = 0; i < dirs.size(); i++)
    {
        switch (dirs[i])
        {
        case 'U':
            road = 0;
            next_road = 1;
            break;

        case 'D':
            road = 1;
            next_road = 0;
            break;

        case 'R':
            road = 2;
            next_road = 3;
            break;

        case 'L':
            road = 3;
            next_road = 2;
            break;
        
        default:
            break;
        }

        int nx = x + dx[road];
        int ny = y + dy[road];

        if(nx < 0 || ny < 0 || nx > 10 || ny > 10) continue;

        if(!visit[x][y][road] && !visit[nx][ny][next_road])
        {
            visit[x][y][road] = true;
            visit[nx][ny][next_road] = true;
            answer++;
        }

        x = nx;
        y = ny;
    }

    return answer;
}