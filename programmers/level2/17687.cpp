#include <string>

using namespace std;

string solution(int n, int t, int m, int p)
{
    string answer;

    for (int i = 0, cnt = 0, length = 0;; i++)
    {
        string temp = i == 0 ? "0" : "";
        for (int j = i; j; j /= n)
        {
            int now = j % n;
            temp = (char)(now >= 10 ? ('A' + now - 10) : (now + '0')) + temp;
        }
        for (int j = 0; j < temp.length(); j++)
        {
            if ((length + j) % m == p - 1)
            {
                answer += temp[j];
                cnt++;
                if (cnt == t)
                    return answer;
            }
        }
        length += temp.length();
    }
}