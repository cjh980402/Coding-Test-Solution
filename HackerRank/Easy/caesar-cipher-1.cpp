#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */
string caesarCipher(const string &s, int k)
{
    string answer;

    for (char c : s)
    {
        // 소문자와 대문자 모두 알파벳 범위를 벗어나지 않게 하는 나머지 연산이 필요하다.
        if (islower(c))
        {
            answer += ('a' + (c - 'a' + k) % 26);
        }
        else if (isupper(c))
        {
            answer += ('A' + (c - 'A' + k) % 26);
        }
        else
        {
            answer += c;
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, k;
    string s;

    cin >> n >> s >> k;

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}