#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    int wordIndex = 0;

    for (char &c : s)
    {
        if (c == ' ')
            wordIndex = 0;
        else
        {
            c = (wordIndex % 2) ? tolower(c) : toupper(c);
            wordIndex++;
        }
    }

    return s;
}