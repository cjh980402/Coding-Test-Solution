#include <string>

using namespace std;

string solution(string s)
{
    return s.substr((s.length() - 1) / 2, s.length() % 2 ? 1 : 2);
}