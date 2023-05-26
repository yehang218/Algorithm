#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
    int N; // 전체 사람의 수
    cin >> N;

    vector<int> person[51];

    for(int i = 0; i<N; i++){
        int tall; // 키 담을 변수
        int weigh; // 몸무게 담을 변수
        cin >> tall >> weigh;
        person[i].push_back(tall); // person[i]의 0번째 요소 : 키
        person[i].push_back(weigh); // person[i]의 1번째 요소 : 몸무게
        person[i].push_back(1); // person[i]의 2번째 요소 : 순위
    }

    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++)
        {
            if(person[i][0]>person[j][0] && person[i][1] > person[j][1]) // 키. 몸무게 비교 시 앞이 크면
            {
                person[j][2]++;
            }
        }
    }

    for(int i = 0;i<N;i++){
        cout << person[i][2] << ' ';
    }

    return 0;
}
