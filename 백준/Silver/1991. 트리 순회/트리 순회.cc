#include <iostream>

using namespace std;

int N;
int tree[50][2];

void input()
{
    char a, b, c;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;
        int a1 = a - 'A';
        if (b == '.')
        {
            tree[a1][0] = -1;
        }
        else
        {
            tree[a1][0] = b - 'A';
        }

        if (c == '.')
        {
            tree[a1][1] = -1;
        }
        else
        {
            tree[a1][1] = c - 'A';
        }
    }
}

// 전위 순회
void preorder(int n)
{
    if (n == -1)
        return;
    cout << (char)(n + 'A');
    preorder(tree[n][0]);
    preorder(tree[n][1]);
}

// 중위 순회
void inorder(int n)
{
    if (n == -1)
        return;
    inorder(tree[n][0]);
    cout << (char)(n + 'A');
    inorder(tree[n][1]);
}

// 후위 순회
void postorder(int n)
{
    if (n == -1)
        return;
    postorder(tree[n][0]);
    postorder(tree[n][1]);
    cout << (char)(n + 'A');
}

int main(void)
{
    input();
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
}