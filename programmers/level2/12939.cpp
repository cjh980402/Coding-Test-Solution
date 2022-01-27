#include <string>
#include <sstream>

using namespace std;

string solution(string s)
{
    int min = 2147483647, max = -2147483648, temp;
    istringstream stream(s);

    while (stream >> temp)
    {
        if (temp < min)
            min = temp;
        if (max < temp)
            max = temp;
    }

    return to_string(min) + " " + to_string(max);
}