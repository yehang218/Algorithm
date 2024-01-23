#include<iostream>
#include<algorithm>

using namespace std;

int N, M; // 배열 A의 크기, 배열 B의 크기
int arr[2000002];

void combineArr()
{
	cin >> N >> M;

	for (int i = 0; i < N + M; i++)
	{
		cin >> arr[i];
	}

	int size = N + M;
	sort(arr, arr + size);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	combineArr();

	for (int i = 0; i < N + M; i++)
	{
		cout << arr[i] << " ";
	}
}