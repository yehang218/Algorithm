#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    int min = 0;
    vector<int> answer = arr;
    sort(arr.begin(), arr.end());
    min =  arr.front();

    for(int i = 0; i < answer.size(); i++)
    {
        if(answer[i] == min)
        {
            answer.erase(answer.begin()+i);
            if(answer.size() == 0) answer.push_back(-1);
            return answer;
        }
    }

    return answer;
}