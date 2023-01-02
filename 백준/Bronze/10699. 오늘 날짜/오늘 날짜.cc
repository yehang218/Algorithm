#include<iostream>
#include<time.h> //time 관련 함수 정의된 헤더

using namespace std;

int main(void)
{
    time_t curTime = time(NULL);
    struct tm *pLocal = localtime(&curTime);

    cout << pLocal->tm_year+1900 << "-";
    cout.width(2);
    cout.fill('0');
    cout << pLocal->tm_mon + 1 << "-";
    cout.width(2);
    cout.fill('0');
    cout << pLocal->tm_mday;
}
