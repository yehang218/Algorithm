#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

map<string, pair<int, int>> m_keypad; // 키패드 번호, 좌표값

void initMap()
{
    for (int i = 0; i < 9; i++)
    {
        m_keypad.insert({to_string(i + 1), {i / 3, i % 3}});
    }
    m_keypad.insert({"*", {3, 0}});
    m_keypad.insert({"0", {3, 1}});
    m_keypad.insert({"#", {3, 2}});
}

float getDistance(string temp, int target)
{
    int temp_x = m_keypad[temp].first;
    int temp_y = m_keypad[temp].second;
    int target_x = m_keypad[to_string(target)].first;
    int target_y = m_keypad[to_string(target)].second;

    return abs(temp_x - target_x) + abs(temp_y - target_y);
}

string checkCloseHand(string r_temp, string l_temp, int target)
{
    if (getDistance(r_temp, target) > getDistance(l_temp, target))
        return "L";
    else if (getDistance(r_temp, target) < getDistance(l_temp, target))
        return "R";
    else
        return "S";
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    initMap();

    string r_temp = "#";
    string l_temp = "*";

    string check = "";
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
            check = "L";
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
            check = "R";
        else
            check = checkCloseHand(r_temp, l_temp, numbers[i]);

        if (check == "L")
            l_temp = to_string(numbers[i]);
        else if (check == "R")
            r_temp = to_string(numbers[i]);
        else
        {
            // 거리가 같다면
            if (hand == "left")
            {
                l_temp = to_string(numbers[i]);
                check = "L";
            }
            else if (hand == "right")
            {
                r_temp = to_string(numbers[i]);
                check = "R";
            }
        }
        answer += check;
    }

    return answer;
}