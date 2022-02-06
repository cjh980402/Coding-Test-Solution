#include <string>
#include <algorithm>

using namespace std;

string solution(string s)
{
    sort(s.rbegin(), s.rend()); // 내림차순 정렬

    return s;
}