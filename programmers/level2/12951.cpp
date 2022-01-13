#include <string>
#include <iostream>

using namespace std;

string solution(string s)
{
    bool wordStart = true;

    for (char &c : s)
    {
        if (c == ' ')
        {
            wordStart = true;
        }
        else if (wordStart)
        {
            wordStart = false;
            c = toupper(c);
        }
        else
        {
            wordStart = false;
            c = tolower(c);
        }
    }

    return s;
}