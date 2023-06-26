#include<iostream>
#include<vector>

using namespace std;
vector<int> v;

void solve(int index)
{

    if(index == 5){
        for(int i = 0; i< index; i++)
        {
            cout << v[i] << ' ';
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < 5; i++) // 0 0 0 0 0
    {
        v.push_back(i);
        solve(index+1);
        v.pop_back();
    }
}

int main(void)
{
    solve(0);
}