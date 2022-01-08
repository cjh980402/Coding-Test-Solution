#include <string>
#include <vector>

using namespace std;

string solution(int n)
{
    string answer = "";
    for (; n; n /= 3)
    {
        int mod = n % 3;
        if (mod == 0)
        {
            answer = "4" + answer;
            n -= 3;
        }
        else
        {
            answer = (mod == 1 ? "1" : "2") + answer;
        }
    }
    return answer;
}