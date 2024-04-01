#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> student1;
vector<int> student2;
vector<int> student3;

void setStudent(int n)
{
    int arr_stu3[5] = {3, 1, 2, 4, 5};

    int num = 0;
    int num2 = 0;
    int num3 = 0;

    for (int i = 0; i < n; i++)
    {
        num++;
        if (num > 5)
            num = 1;
        student1.push_back(num);

        if (i % 2 == 0)
            student2.push_back(2);
        else
        {
            num2++;
            if (num2 == 2)
                num2++;
            if (num2 > 5)
                num2 = 1;
            student2.push_back(num2);
        }

        if (i % 2 == 0)
            num3++;
        if (num3 > 5)
            num3 = 1;
        student3.push_back(arr_stu3[num3 - 1]);
    }
}

int checkAnswer(vector<int> student, vector<int> answers)
{
    int correctQuestions = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (student[i] == answers[i])
            correctQuestions++;
    }
    return correctQuestions;
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    int len = answers.size();
    setStudent(len);

    vector<int> answerStu;
    vector<int> answerStuTemp;
    answerStu.push_back(checkAnswer(student1, answers));
    answerStu.push_back(checkAnswer(student2, answers));
    answerStu.push_back(checkAnswer(student3, answers));

    answerStuTemp = answerStu;
    sort(answerStuTemp.begin(), answerStuTemp.end(), greater<int>());
    int maxAnswer = answerStuTemp.front();

    for (int i = 0; i < answerStu.size(); i++)
    {
        if (maxAnswer == answerStu[i])
            answer.push_back(i + 1);
    }
    sort(answer.begin(), answer.end());

    return answer;
}