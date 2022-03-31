#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string pangrams(const string &s)
{
    bool hasAlpha[26] = {false};
    int count = 0;

    for (char c : s)
    {
        char lc = tolower(c);
        if (isalpha(lc) && !hasAlpha[lc - 'a'])
        {
            hasAlpha[lc - 'a'] = true;
            count++;
        }
    }

    return count == 26 ? "pangram" : "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}