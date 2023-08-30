#include<iostream>
#include<queue>
#include<stdlib.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int x;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    cin >> N;

    for(int i = 0; i< N; i++)
    {
        cin >> x;
        if(x != 0){
            pq.push({abs(x), x});
        }
        else{
            if(pq.empty()){
                cout << "0" << "\n";
                continue;
            }
            cout << pq.top().second << "\n";
            pq.pop();
        }
    }

}