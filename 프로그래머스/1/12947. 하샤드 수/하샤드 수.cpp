#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int num = 0;
    for(char c : to_string(x))
        num += c - '0';

    return (x % num == 0);
}