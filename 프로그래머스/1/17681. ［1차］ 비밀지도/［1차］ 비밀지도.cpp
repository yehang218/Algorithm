#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    string str_map1; 
    string str_map2;

    for(int i = 0; i < n;  i++)
    {
        bitset<16> map1(arr1[i]);
        bitset<16> map2(arr2[i]);

        str_map1 = map1.to_string().substr(16-n, n);
        str_map2 = map2.to_string().substr(16-n, n);

        string ans = "";
        for(int j = 0; j < n;  j++)
        {
            if(str_map1[j] == '0' && str_map2[j] == '0')
            {
                ans = ans + ' ';
            }
            else{
                ans = ans + '#';
            }
        }
        answer.push_back(ans);
    }

    return answer;
}