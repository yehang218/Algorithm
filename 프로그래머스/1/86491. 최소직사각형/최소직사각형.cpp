#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    vector<int> max_sizes;
    vector<int> min_sizes;

    for(vector<int> size : sizes)
    {
        max_sizes.push_back(max(size[0], size[1]));
        min_sizes.push_back(min(size[0], size[1]));
    }

    answer = *max_element(max_sizes.begin(), max_sizes.end());
    answer *= *max_element(min_sizes.begin(), min_sizes.end());

    return answer;
}