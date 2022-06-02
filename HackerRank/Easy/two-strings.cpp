#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
string twoStrings(const string &s1, const string &s2)
{
    int count1[26] = {0}, count2[26] = {0};

    for (char c : s1)
    {
        count1[c - 'a']++;
    }
    for (char c : s2)
    {
        count2[c - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (count1[i] > 0 && count2[i] > 0)
        {
            return "YES"; // 겹치는 문자가 하나라도 존재하면 일치하는 substring이 존재하는 경우이다.
        }
    }

    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.get();

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}