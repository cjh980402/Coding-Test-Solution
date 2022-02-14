#include <string>

using namespace std;

string solution(int n)
{
    string answer;

    for (int i = 0; i < n / 2; i++)
    {
        answer += "수박";
    }

    return answer + (n % 2 ? "수" : "");
}