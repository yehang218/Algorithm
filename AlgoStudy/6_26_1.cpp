#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

int check[3];

void solve(int index)
{
    if(index == 3)
    {
        for(int i = 0; i<index; i++){
            cout << v[i] << ' ';
        }
        cout << endl;
        return;
    }

    for(int i = 0; i<5; i++){
        if(check[i] == 1) continue;
        v.push_back(i);
        check[i] = 1;
        solve(index+1);
        v.pop_back();
        check[i] = 0;
    }

}

int main(void)
{
    solve(0);
}