#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string str1 = to_string(a) + to_string(b);
    string str2 = to_string(b) + to_string(a);

    int num1 = stoi(str1);
    int num2 = stoi(str2);

    answer = max(num1, num2);

    return answer;
}