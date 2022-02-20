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
    long long answer = 0;
    vector<pair<char, int>> info;

    info.push_back(make_pair(s[0], 1));
    for (int i = 1; i < s.size(); i++)
    {
        if (info.back().first == s[i])
        {
            // 이전 글자와 같은 경우 카운팅 증가
            info.back().second++;
        }
        else
        {
            // 이전 글자와 다른 경우 새 문자의 데이터 추가
            info.push_back(make_pair(s[i], 1));
        }
    }
    // 위의 과정을 거치면 abba는 {(a, 1), (b, 2), (a, 1)}로 변환된다.

    for (const pair<char, int> &p : info)
    {
        if (p.second > 1)
        {
            answer++; // 카운트가 1보다 큰 경우, 해당 구역에서 2개를 제거하는 경우는 모두 같은 문자열이 되므로 답을 1씩 증가시킨다.
        }
    }

    for (int i = 1; i + 1 < s.size(); i++)
    {
        if (s[i - 1] == s[i + 1] && s[i] != s[i - 1])
        {
            // 연속된 3개의 문자가 aba와 같은 경우에 해당한다. 이러한 경우, ab를 제거하나 ba를 제거하나 결과가 같기때문에 답을 1씩 감소시킨다. (중복제거)
            answer--;
        }
    }

    answer += info.size() * (info.size() - 1) / 2; // info.size() * (info.size() - 1) / 2는 info에서 2개를 뽑는 경우의 수로 각 info의 원소에서 하나씩 제거하는 경우에 해당한다.

    return answer;
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