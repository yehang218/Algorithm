#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s_answer;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        for(int j = i + 1; j < numbers.size(); j++)
        {
            s_answer.insert(numbers[i] + numbers[j]);
        }
    }

    answer = vector<int>(s_answer.begin(), s_answer.end());
    return answer;
}