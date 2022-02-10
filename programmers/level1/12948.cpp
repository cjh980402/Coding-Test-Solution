#include <string>

using namespace std;

string solution(string phone_number)
{
    int starEnd = phone_number.size() - 4;
    return string(starEnd, '*') + phone_number.substr(starEnd);
}