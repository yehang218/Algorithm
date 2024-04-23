// 문제 분석
/*
1. 8진수 -> 10진수 -> 2진수
    1.1 숫자의 범위가 333334 이하가 아니라 수의 길이가 333334 이하이기 때문에, int나 long long으로 처리하기 힘들다.
    => 문자열을 이용해야 함!
    1.2 8진수에서 10으로 변환하는 과정에서 숫자로 된 값이 필요하므로 이 방법으로 풀긴 어렵다
2. 8진수 -> 2진수
    => 8은 2의 3승이므로 8진수의 각 자리수를 2진수의 세자리씩 차지하게 넣어주면 된다! ex) 35 -> 011101 (3 -> 011 / 5 -> 101)
    진법 변환 참고 : https://blog.naver.com/icbanq/221727893563
    => 배열에 각 0~7까지 담아두고 8진수의 각 자리수를 index로 처리해버리기!
*/

#include <iostream>
#include <string>

using namespace std;

string binary[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

void conversion(string oct_num)
{
    int index = 0;
    for (int i = 0; i < oct_num.length(); i++)
    {
        index = oct_num[i] - '0';

        // 맨 처음 출력하는 경우라면 앞에 0이 나오면 안됨
        if (i == 0) cout << stoi(binary[index]);
        else cout << binary[index];
    }
}

int main(void)
{
    string oct_num;
    cin >> oct_num;

    if (oct_num == "0") cout << oct_num;
    else conversion(oct_num);
}