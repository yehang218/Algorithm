#include <string>
#include <vector>
#include<sstream>
#include<algorithm>

using namespace std;

vector<string> solution(string myString) {
	vector<string> answer;
	istringstream iss(myString);
	string token;

	while (getline(iss, token, 'x'))
	{
        if(token == "") continue;
		answer.push_back(token);
	}
    
    sort(answer.begin(), answer.end());
    
	return answer;
}