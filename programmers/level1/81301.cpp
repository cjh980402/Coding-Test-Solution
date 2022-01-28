#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size();)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            answer = 10 * answer + (s[i] - '0');
            i++;
        }
        else if (string_view{s.data() + i, 2} == "ze")
        {
            answer = 10 * answer;
            i += 4;
        }
        else if (string_view{s.data() + i, 2} == "on")
        {
            answer = 10 * answer + 1;
            i += 3;
        }
        else if (string_view{s.data() + i, 2} == "tw")
        {
            answer = 10 * answer + 2;
            i += 3;
        }
        else if (string_view{s.data() + i, 2} == "th")
        {
            answer = 10 * answer + 3;
            i += 5;
        }
        else if (string_view{s.data() + i, 2} == "fo")
        {
            answer = 10 * answer + 4;
            i += 4;
        }
        else if (string_view{s.data() + i, 2} == "fi")
        {
            answer = 10 * answer + 5;
            i += 4;
        }
        else if (string_view{s.data() + i, 2} == "si")
        {
            answer = 10 * answer + 6;
            i += 3;
        }
        else if (string_view{s.data() + i, 2} == "se")
        {
            answer = 10 * answer + 7;
            i += 5;
        }
        else if (string_view{s.data() + i, 2} == "ei")
        {
            answer = 10 * answer + 8;
            i += 5;
        }
        else if (string_view{s.data() + i, 2} == "ni")
        {
            answer = 10 * answer + 9;
            i += 4;
        }
    }

    return answer;
}