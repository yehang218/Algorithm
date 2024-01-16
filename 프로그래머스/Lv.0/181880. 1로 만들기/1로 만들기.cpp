#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
	int answer = 0;
	int N;

	for (int i = 0; i < num_list.size(); i++)
	{
		N = num_list[i];
		while (N > 1)
		{
			if (N % 2 == 0) N = N / 2;
			else if (N % 2 == 1)
			{
				N = N - 1;
				N = N / 2;
			}
			answer++;
		}
	}

	return answer;
}
