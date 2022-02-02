#include <string>

using namespace std;

string solution(string s, int n)
{
    for (char &c : s)
    {
        // 나머지 연산을 사용했으므로 z를 넘어가면 다시 a부터 시작됨
        if (islower(c))
        {
            c = (c - 'a' + n) % 26 + 'a';
        }
        else if (isupper(c))
        {
            c = (c - 'A' + n) % 26 + 'A';
        }
    }

    return s;
}