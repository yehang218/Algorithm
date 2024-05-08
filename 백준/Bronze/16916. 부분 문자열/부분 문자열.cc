// 문제 분석
/*
 이중 for문 가능?
 -> 문자열 길이가 100만이므로 100만*100만 = 1조 라서 시간 제한에 걸릴듯!
 문자열 찾기(find)로 해보쟈! -> 이렇게 해도 시간 초과가 뜨네
 find의 시간 복잡도는 O(NM)
 GCC의 라이브러리 구현인 libstd C++에서 strstr의 시간 복잡도 O(N+M) 이라서
 strstr로 구현해야함!
-> 근데 strstr은 매개변수를 string으로 받는게 아니라 char*으로 받기 때문에 string을 char*로 변환해야 한다.
이때, 사용하는 함수가 c_str()이다!
*/

#include <iostream>
#include <cstring>

using namespace std;

string full_str;
string sub_str;

void input()
{
    cin >> full_str;
    cin >> sub_str;
}

int solve()
{
    // if (full_str.find(sub_str) == string::npos) return 0;
    // return 1;

    if (strstr(full_str.c_str(), sub_str.c_str()) != NULL) return 1;
    return 0;
}

int main(void)
{
    input();
    cout << solve();
}