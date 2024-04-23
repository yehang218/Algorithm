// 문제 분석
/*
2진수 -> 8진수
3자리씩 끊어서 문자열로 바꾸기 ("BOJ 1212번 - 8진수 2진수"랑 고냥 반대)
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m_num{{"000", 0}, {"001", 1}, {"010", 2}, {"011", 3}, {"100", 4}, {"101", 5}, {"110", 6}, {"111", 7} };

void conversion(string binary_num)
{
    string temp = "";

    // 만약 앞에 0이 생략된 경우라면 앞에 0 추가
    int remainder = binary_num.length() % 3;
    if(remainder != 0)
    {
        int zero_plus = 3 - remainder;
        for(int i = 0; i < zero_plus; i++) binary_num = "0" + binary_num;
    }

    for(int i = 0; i < binary_num.length(); i++)
    {
        temp = temp + binary_num[i];
        if(i % 3 == 2)
        {
            cout << m_num[temp];
            temp = "";
        }
    }
}

int main(void)
{
    string binary_num ="";
    cin >> binary_num;

    conversion(binary_num);
}