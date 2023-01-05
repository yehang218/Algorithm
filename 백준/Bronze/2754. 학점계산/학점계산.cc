#include<iostream>
using namespace std;

float check_plus(char p)
{
    float score = 0.0;

    return score;
}

int main(void)
{
    char grade[3];
    float score = 4.0;
    cin >> grade;

    if(grade[0] == 'F')
    {
        cout << "0.0";
        return 0;
    }

    if(grade[0] == 'A') {
        score = 4.0;
        if(grade[1] =='0') {
            cout << "4.0";
            return 0;
        }
    }
    else if(grade[0] == 'B') {
        score = 3.0;
        if(grade[1] =='0') {
            cout << "3.0";
            return 0;
        }
    }
    else if(grade[0] == 'C') {
        score = 2.0;
        if(grade[1] =='0') {
            cout << "2.0";
            return 0;        
        }
    }
    else if(grade[0] == 'D') {
        score = 1.0;
        if(grade[1] =='0') {
            cout << "1.0";
            return 0;   
        }     
    }

    if(grade[1] == '+') score += 0.3;
    else if(grade[1] == '-') score += -0.3;
    
    cout << score;

    return 0;
}