#include <string>
#include <vector>

using namespace std;

string reverse3(int n)
{
    string s;
    for (; n; n /= 3)
        s += (char)(n % 3 + '0');
    return s;
}

int solution(int n)
{
    int answer = 0;

    for (char c : reverse3(n))
    {
        answer = 3 * answer + (c - '0');
    }

    return answer;
}