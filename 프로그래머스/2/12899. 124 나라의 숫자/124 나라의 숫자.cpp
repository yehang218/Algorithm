// 문제 분석
/*
숫자 증가 -> 1,2,4만 사용해서 표현

=> 3개의 숫자를 사용하므로 3진수
3으로 나눴을 때 
1(->1)은 나머지가 1 /2(->2)는 나머지 2 / 3(->4)은 나머지 0이므로
배열을 4, 1, 2로 만들어서 배열[나머지]를 더해주기

만약 n이 3으로 나누어 떨어지면 몫이 1이 생김 -> -1 해줘야함
*/

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    char fot[3] = {'4', '1', '2'};

    while(n > 0)
    {
        int index_num = n % 3;
        answer = fot[index_num] + answer;

        n = n / 3;

        if(index_num == 0)
            n = n - 1;
    }

    return answer;
}
