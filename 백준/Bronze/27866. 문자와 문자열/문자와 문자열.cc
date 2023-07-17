#include <iostream>
#include <string>

using namespace std;

string word;
int i;

void input()
{
    cin >> word;
    cin >> i;
}

void print()
{
    cout << word[i - 1];
}

int main(void)
{
    input();
    print();
}