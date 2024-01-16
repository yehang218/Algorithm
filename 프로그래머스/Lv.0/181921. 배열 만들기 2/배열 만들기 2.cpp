#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
	vector<int> answer;

	string strNum = "";
	int check = 0;

	for (int i = l; i <= r; i++)
	{
		strNum = to_string(i);
		check = 0;

		for (int j = 0; j < strNum.length(); j++)
		{
			if (strNum[j] == '5') check++;
			else if (strNum[j] == '0') check++;
			else break;
		}

		if (check == strNum.length()) {
			answer.push_back(i);
		}
	}

	if (answer.size() == 0) answer.push_back(-1);

	return answer;
}
