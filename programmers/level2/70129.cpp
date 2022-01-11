#include <string>
#include <vector>

using namespace std;

string itobin(int i)
{
    string s;

    for (; i; i /= 2)
        s = to_string(i % 2) + s;

    return s;
}

vector<int> solution(string s)
{
    vector<int> answer(2);

    while (s != "1")
    {
        string rmZero;
        for (char c : s)
        {
            if (c == '1')
                rmZero += c;
        }
        answer[1] += (s.length() - rmZero.length());
        answer[0]++;

        s = itobin(rmZero.length());
    }

    return answer;
}