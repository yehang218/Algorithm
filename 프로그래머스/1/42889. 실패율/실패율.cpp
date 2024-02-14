#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int failurePlayer[505];
int reachPlayer[505];

bool compare(pair<float, int> a, pair<float, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<pair<float, int>> v;

    sort(stages.begin(), stages.end());

    int playerInStage = 0;
    int stageNum = 0;
    for (int i = 0; i < stages.size(); i++)
    {
        // 새로운 스테이지라면
        if (stages[i] != stageNum)
        {
            playerInStage = 0;
            stageNum = stages[i];
        }
        playerInStage++;
        failurePlayer[stageNum]++;
    }

    int player = 0;
    for (int i = 1; i <= N; i++)
    {
        player = player + failurePlayer[i - 1];
        reachPlayer[i] = stages.size() - player;
        float failureRate = (float)failurePlayer[i] / (stages.size() - player);
        if(reachPlayer[i] == 0) failureRate = 0;
        v.push_back(make_pair(failureRate, i));
    }

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < N; i++)
    {
        answer.push_back(v[i].second);
    }

    return answer;
}