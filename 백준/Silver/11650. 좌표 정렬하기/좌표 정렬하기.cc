#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

int main(void)
{
    int N, x, y;
    vector<pair<int, int>> vec_num;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        vec_num.push_back({x, y});
    }

    sort(vec_num.begin(), vec_num.end(), compare);

    for (int i = 0; i < vec_num.size(); i++)
        cout << vec_num[i].first << " " << vec_num[i].second << "\n";
}