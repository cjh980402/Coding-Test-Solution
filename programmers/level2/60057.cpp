#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = s.length();

    for (int i = 1; i < s.length(); i++)
    {
        string result, temp1, temp2;
        int same = 1;
        for (int j = 0; j <= s.length(); j += i)
        {
            temp1 = s.substr(j, i);
            temp2 = (j + i < s.length()) ? s.substr(j + i, i) : "";
            if (temp1 == temp2)
            {
                same++;
            }
            else
            {
                if (same == 1)
                {
                    result += temp1;
                }
                else
                {
                    result += (to_string(same) + temp1);
                    same = 1;
                }
            }
        }
        if (answer > result.length())
        {
            answer = result.length();
        }
    }

    return answer;
}