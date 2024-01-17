#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
#include <map>
#include <cstdlib>
#include <cmath>
using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
	return a.second > b.second;
}

int solution(int a, int b, int c, int d) {
	int answer = 0;
	int arr[7] = { 0, 0, 0, 0, 0, 0, 0 };
	arr[a]++; arr[b]++; arr[c]++; arr[d]++;

	map<int, int> m;
	m[a] = arr[a];
	m[b] = arr[b];
	m[c] = arr[c];
	m[d] = arr[d];

	vector<pair<int, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), comp);

	if (v[0].second == 4)
	{
		// 모두 같은 수
		return 1111 * v[0].first;
	}

	else if (v[0].second == 3)
	{
		// 3 , 1
		answer = 10 * v[0].first + v[1].first;
		return pow(answer, 2);
	}

	else if (v[0].second == 2)
	{
		// 2, 2
		
		if (v[1].second == 2)
		{
			int sub = abs(v[0].first - v[1].first);
			return (v[0].first + v[1].first) * sub;
		}

		// 2, 1, 1
		else if (v[1].second == 1)
		{
			return v[1].first * v[2].first;
		}
	}

	else if (v[1].second == 1)
	{
		// 모두 다 다른 경우
		// 최소값 반환
		sort(v.begin(), v.end());
		return v[0].first;
	}

	return answer;
}