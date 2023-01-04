#include<iostream>
using namespace std;

int main(void)
{
    char word[101];

    cin >> word;
    
    for(int i = 0; word[i] != '\0'; i++)
    {
        if(word[i] >= 97 && word[i] <= 122) //소문자라면
            word[i] = word[i] - 32; // 대문자로 바꾸기
        else if(word[i] >= 65 && word[i] <= 90) //대문자라면
            word[i] = word[i] + 32; // 소문자로 바꾸기
    }   

    cout << word;
    return 0;
}