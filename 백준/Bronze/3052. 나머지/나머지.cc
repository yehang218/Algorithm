#include<iostream>
#include <set>

using namespace std;

int main(void)
{
    int num = 0;
    set<int> remain_num;
    for(int i = 0; i < 10; i++)
    {
        cin >> num;
        remain_num.insert(num % 42);
    }

    cout << remain_num.size();
}