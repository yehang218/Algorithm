#include<iostream>
using namespace std;

long long Tree[1000001]; // 나무들의 높이

int main(void)
{
    long long N, M;
 
    long long int H = 0; // 자를 나무 높이 최댓값
    long long int maxVal;

    long long int l = 0; // 남은 길이를 담을 변수
    long long int start, end, mid = 0;

    cin >> N >> M;
    for(int i = 0; i< N; i++)
    {
        cin >> Tree[i];
        if(Tree[i] > maxVal) maxVal = Tree[i];
    } 

    start = 0; end = maxVal;
    while(start <= end)
    {
        l = 0;
        mid = (start + end) / 2;
        for(int i = 0; i< N; i++)
        {
            if(Tree[i]- mid > 0) l = l + Tree[i] - mid;
        }
        if(l < M)
        { // 중간보다 작은 경우 탐색
            end = mid - 1;
        }
        else 
        { // 크거나 같은 경우
            H = mid;
            start = mid + 1;
        }
    }
    cout << H;
    
    return 0;
}