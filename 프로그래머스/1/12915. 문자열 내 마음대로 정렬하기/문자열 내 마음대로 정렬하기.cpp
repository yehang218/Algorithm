#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool compare(string str1, string str2)
{
    if(str1[N] == str2[N]) 
        return str1 < str2;
    return str1[N] < str2[N];
}

vector<string> solution(vector<string> strings, int n) {
    N = n;
    sort(strings.begin(), strings.end(), compare);
    return strings;
}
