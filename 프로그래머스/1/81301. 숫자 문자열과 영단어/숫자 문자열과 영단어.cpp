#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, char> mapNum;

void setMap()
{
    mapNum.insert({"zero", '0'});
    mapNum.insert({"one", '1'});
    mapNum.insert({"two", '2'});
    mapNum.insert({"three", '3'});
    mapNum.insert({"four", '4'});
    mapNum.insert({"five", '5'});
    mapNum.insert({"six", '6'});
    mapNum.insert({"seven", '7'});
    mapNum.insert({"eight", '8'});
    mapNum.insert({"nine", '9'});
}

int solution(string s)
{
    int answer = 0;
    string str_answer = "";

    setMap();

    for (int i = 0; i < s.length(); i++)
    {
        // 알파벳이라면
        if (s[i] >= 'a' - 0 && s[i] <= 'z' - 0)
        {
            string tempStr3 = s.substr(i, 3);
            string tempStr4 = s.substr(i, 4);
            string tempStr5 = s.substr(i, 5);

            if (mapNum.find(tempStr3) != mapNum.end())
            {
                str_answer = str_answer + mapNum.at(tempStr3);
                i = i + 2;
            }
            else if (mapNum.find(tempStr4) != mapNum.end())
            {
                str_answer = str_answer + mapNum.at(tempStr4);
                i = i + 3;
            }
            else if (mapNum.find(tempStr5) != mapNum.end())
            {
                str_answer = str_answer + mapNum.at(tempStr5);
                i + i + 4;
            }
        }
        // 숫자라면
        else
        {
            str_answer = str_answer + s[i];
        }
    }
    answer = stoi(str_answer);
    return answer;
}