#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


string solution(string s) {
    istringstream ss(s);
    vector<int> x;
    string stringBuffer;
    string answer = "";
    
    while(getline(ss, stringBuffer, ' '))
    {
        x.push_back(stoi(stringBuffer));
    }

    sort(x.begin(), x.end());
    answer = to_string(x.front()) + " " + to_string(x.back());

    return answer;
}

