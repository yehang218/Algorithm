#include <string>
#include <vector>

using namespace std;


vector<int> solution(vector<int> arr, vector<int> delete_list) {
	vector<int> answer;
	int check = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		check = 0;
		for (int j = 0; j < delete_list.size(); j++)
		{
			if (arr[i] == delete_list[j]) check++;
		}
		if (check == 0) answer.push_back(arr[i]);
	}

	return answer;
}