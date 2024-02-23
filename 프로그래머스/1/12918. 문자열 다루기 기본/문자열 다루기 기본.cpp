#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.length() != 4 && s.length() != 6) return false;
    for(auto sTemp : s)
    {
        if(!isdigit(sTemp)) return false;
    }
    
    return answer;
}