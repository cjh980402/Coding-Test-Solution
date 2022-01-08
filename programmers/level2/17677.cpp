#include <string>
#include <set>

using namespace std;

multiset<string> stringSet(string str)
{
    multiset<string> v;

    for (int i = 0; i < str.length() - 1; i++)
    {
        char c1 = ('a' <= str[i] && str[i] <= 'z') ? str[i] - 32 : str[i];
        char c2 = ('a' <= str[i + 1] && str[i + 1] <= 'z') ? str[i + 1] - 32 : str[i + 1];
        if ('A' <= c1 && c1 <= 'Z' && 'A' <= c2 && c2 <= 'Z')
        {
            v.insert(""s + c1 + c2);
        }
    }

    return v;
}

int solution(string str1, string str2)
{
    multiset<string> A = stringSet(str1), B = stringSet(str2);
    if (A.size() == 0 && B.size() == 0)
        return 65536;
    multiset<string> interSet, unionSet(A), AnBc(A);

    for (string s : B)
    {
        auto sIter = AnBc.find(s);
        if (sIter == AnBc.end())
            unionSet.insert(s); // (A-B) U B
        else
            AnBc.erase(sIter); // A-B
    }

    for (string s : B)
    {
        auto sIter = A.find(s);
        if (sIter != A.end())
        {
            interSet.insert(s);
            A.erase(sIter);
        }
    }

    return 65536 * interSet.size() / unionSet.size();
}