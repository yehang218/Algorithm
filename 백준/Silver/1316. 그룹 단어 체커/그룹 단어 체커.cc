#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    int N; // 입력받을 단어 N
    int group_word = 0; // 정답 개수
    
    cin >> N;
    group_word = N;

    for(int i = 0; i<N; i++){
        string word;
        int alphabet[26] = {0};

        cin >> word;

        for(int j = 0 ; j < word.length(); j++){
            if(j != 0){ // 첫 단어일때는 체크 생략
                if(alphabet[word[j]-97] != 0 && word[j-1] != word[j]){ // 처음 나온 단어가 아닌데 앞이랑 같은 문자도 아니면
                    group_word--; // 그룹 단어에서 제하고 체크도 멈춤
                    break;
                }
            }
            alphabet[word[j]-97]++; // 알파벳가 나온 수 증가
        }
    }
    cout << group_word;
}