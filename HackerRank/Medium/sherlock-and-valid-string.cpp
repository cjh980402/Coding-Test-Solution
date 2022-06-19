#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(const string &s)
{
    int count[26] = {0};
    unordered_map<int, int> countMap;

    for (char c : s)
    {
        count[c - 'a']++; // 각 글자의 개수 카운트
    }

    for (int cnt : count)
    {
        if (cnt > 0)
        {
            countMap[cnt]++; // 각 글자의 개수의 종류를 카운트
        }
    }

    if (countMap.size() == 1)
    {
        return "YES"; // 모든 글자의 개수가 같은 경우
    }
    if (countMap.size() == 2) // 개수가 2종류 존재
    {
        if (countMap.count(1) == 1 && countMap[1] == 1)
        {
            return "YES"; // 하나만 존재하는 글자를 제거하면 되는 경우
        }
        // 두 개수의 차이가 하나이고, 개수가 많은 글자 하나만 제거하면 되는 경우
        auto begin = countMap.begin();
        auto last = ++countMap.begin();
        if (begin->first - last->first == 1 && begin->second == 1)
        {
            return "YES";
        }
        if (last->first - begin->first == 1 && last->second == 1)
        {
            return "YES";
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}