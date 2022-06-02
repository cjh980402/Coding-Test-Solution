#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string gameOfThrones(const string &s)
{
    int count[26] = {0};
    for (char c : s)
    {
        count[c - 'a']++;
    }

    int countOdd = 0;
    for (int i : count)
    {
        countOdd += (i % 2);
    }

    return countOdd <= 1 ? "YES" : "NO"; // 회문의 경우 가운데 글자만 홀수 개가 가능하기 때문에 개수가 홀수인 글자는 1개 이하여야 한다.
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
