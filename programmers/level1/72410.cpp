#include <string>

using namespace std;

string solution(string new_id)
{
    string answer = "";

    // 1~3단계 수행
    for (int i = 0; i < new_id.length(); i++)
    {
        char c = tolower(new_id[i]);
        if (islower(c) || isdigit(c) || c == '-' || c == '_' || (answer.back() != '.' && c == '.'))
        {
            answer += c;
        }
    }

    // 4단계 수행
    if (answer.front() == '.')
    {
        answer = answer.substr(1);
    }
    if (answer.back() == '.')
    {
        answer.pop_back();
    }

    // 5~7단계 수행
    if (answer.length() == 0)
    {
        answer = "a";
    }
    if (answer.length() >= 16)
    {
        answer = answer.substr(0, 15 - (answer[14] == '.' ? 1 : 0));
    }
    else if (answer.length() <= 2)
    {
        answer += string(3 - answer.length(), answer.back());
    }

    return answer;
}