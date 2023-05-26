#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int minus = 1;
    int ten = 1;
    
    if(s.at(0) == '-'){
        minus = -1;  
    }
        
    for(int i = s.length()-1; i>=0;i--)
    {
        if(s[i] == '-' || s[i] == '+') continue;
        answer = answer + ten * (s[i] - '0');
        ten = ten * 10;
    }
    answer = answer * minus;
    return answer;
}