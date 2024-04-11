#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int count = 0;
    if(num == 1) return 0;
    while(true)
    {
        if(count == 500) return -1;
        
        count++; 
        num = num % 2 == 1 ? (num * 3 + 1) : num / 2;
        if(num == 1) break;
        
    }

    return count;
}