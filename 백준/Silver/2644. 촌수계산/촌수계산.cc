#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;                     // 전체 사람의 수
int person1, person2;      // 촌수를 계산해야 하는 다른 두사람의 번호
int m;                     // 부모 자식들 간의 관계의 개수
int p, c;                  // 부모, 자식
vector<int> relation[101]; // 관계
queue<int> q;
int check[101];
int first;

int main(void)
{

    cin >> n;
    cin >> person1 >> person2;
    cin >> m;

    if (person1 > n || person2 > n)
    {
        cout << "-1";
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> p >> c;
        relation[p].push_back(c);
        relation[c].push_back(p);
    }

    q.push(person1);
    check[person1]++;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < relation[x].size(); i++)
        {
            int y = relation[x][i];
            if (check[y] == 0)
            {
                q.push(y);
                check[y] = check[x] + 1;
                if (y == person2)
                {
                    cout << check[person2] - 1;
                    return 0;
                }
            }
        }
    }
    cout << "-1";
}