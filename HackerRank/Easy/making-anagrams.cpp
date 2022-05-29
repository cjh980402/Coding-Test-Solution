#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
int makingAnagrams(const string &s1, const string &s2)
{
    int count1[26] = {0}, count2[26] = {0};
    for (char c : s1)
    {
        count1[c - 'a']++; // s1에 존재하는 각 문자의 개수
    }
    for (char c : s2)
    {
        count2[c - 'a']++; // s2에 존재하는 각 문자의 개수
    }

    int answer = 0;
    for (int i = 0; i < 26; i++)
    {
        answer += abs(count2[i] - count1[i]); // 삭제할 문자의 개수 = 양 측에서 서로 다른 문자의 개수
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1, s2;
    cin >> s1 >> s2;

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
