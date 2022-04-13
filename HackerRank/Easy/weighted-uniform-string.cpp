#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */
vector<string> weightedUniformStrings(const string &s, const vector<int> &queries)
{
    vector<string> answer;
    unordered_set<int> scores;

    int sameCount = 1;
    char before = '\0';

    for (char c : s)
    {
        if (before == c)
        {
            sameCount++;
        }
        else
        {
            sameCount = 1;
        }
        scores.insert((c - 'a' + 1) * sameCount);
        before = c;
    }

    for (int q : queries)
    {
        answer.push_back(scores.find(q) == scores.end() ? "No" : "Yes");
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++)
    {
        cin >> queries[i];
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i] << "\n";
    }

    fout.close();

    return 0;
}