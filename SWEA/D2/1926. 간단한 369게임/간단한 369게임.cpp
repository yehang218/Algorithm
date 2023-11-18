#include<iostream>
#include <stdio.h>
#include<string>

using namespace std;

void solve(int N)
{
	for (int i = 1; i <= N; i++)
	{
		int count = 0; // 3, 6, 9의 개수
		string str = to_string(i);
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == '3' || str[j] == '6' || str[j] == '9')
			{
				count++;
			}
		}

		if (count == 0) cout << i;
		else
		{
			for (int j = 0; j < count; j++)
			{
				cout << "-";
			}
		}
		cout << " ";
	}
}

int main(int argc, char** argv)
{
	int N;

	//freopen("input.txt", "r", stdin);
	cin >> N;
	solve(N);

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}