#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    string command = "";
    string userid = "";
    string nickname = "";

    map<string, string> db; // userid, nickname

    for(int i = 0; i < record.size(); i++)
    {
        // Enter userid nickname
        // Change userid nickname
        if(record[i][0] == 'E' || record[i][0] == 'C')
        {
            stringstream data(record[i]);
            data >> command >> userid >> nickname;
            db[userid] = nickname;
        }
    }

    for(string message : record)
    {
        // Enter userid nickname
        if(message[0] == 'E')
        {
            stringstream data(message);
            data >> command >> userid >> nickname;

            answer.push_back(db[userid] + "님이 들어왔습니다.");
        }

        // Leave userid
        else if(message[0] == 'L')
        {
            stringstream data(message);
            data >> command >> userid;

            answer.push_back(db[userid] + "님이 나갔습니다.");
        }
    }

    return answer;
}