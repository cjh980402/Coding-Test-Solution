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
            sameCount++; // 동일한 글자가 나온 경우 카운트 증가
        }
        else
        {
            sameCount = 1; // 다른 글자가 나온 경우 카운트 리셋
        }
        scores.insert((c - 'a' + 1) * sameCount); // 현재 글자에서의 점수 추가
        before = c;
    }

    for (int q : queries)
    {
        answer.push_back(scores.find(q) == scores.end() ? "No" : "Yes"); // 점수의 존재 유무에 따라 값 결정
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