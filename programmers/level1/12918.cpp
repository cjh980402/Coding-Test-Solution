#include <string>

using namespace std;

bool solution(string s)
{
    int len = s.size();

    if (len == 4 || len == 6)
    {
        for (char c : s)
        {
            if (!isdigit(c))
                return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}