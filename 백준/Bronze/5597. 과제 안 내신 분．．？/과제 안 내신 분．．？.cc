#include<iostream>
using namespace std;

int main(void)
{
    int stu[31] = {0};
    int x = 32;
    for(int i = 0; i < 28; i++)
    {
        cin >> x;
        stu[x]++; 
    }
    for(int i = 1; i < 31; i++)
    {
        if(stu[i] == 0)
            cout << i << endl;
    }
}