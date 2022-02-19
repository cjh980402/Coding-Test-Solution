#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'beautifulStrings' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts STRING s as parameter.
 */
long long beautifulStrings(string s)
{
    unordered_set<string> cache;

    // 현재 코드는 시간초과가 발생하는 코드이다.
    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            string temp(s);
            temp.erase(temp.begin() + i);
            temp.erase(temp.begin() + j - 1);
            cache.insert(temp);
        }
    }

    return cache.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long long result = beautifulStrings(s);

    fout << result << "\n";

    fout.close();

    return 0;
}