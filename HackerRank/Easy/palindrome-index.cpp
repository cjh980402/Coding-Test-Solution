#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int palindromeIndex(const string &s)
{
    int answer = -1;

    for (int i = 0; i < s.size() / 2; i++)
    {
        // 다른 글자가 발견된 경우 글자를 지운 후 회문 검사 수행
        if (s[i] != s[s.size() - 1 - i])
        {
            int j;
            // i번째 글자를 지우는 경우에 대해 회문 검사
            for (j = i; j < s.size() / 2; j++)
            {
                if (s[j + 1] != s[s.size() - 1 - j])
                    break;
            }
            if (j == s.size() / 2)
            {
                answer = i;
                break;
            }

            // (s.size() - 1 - i)번째 글자를 지우는 경우에 대해 회문 검사
            for (j = i; j < s.size() / 2; j++)
            {
                if (s[j] != s[s.size() - 2 - j])
                    break;
            }
            if (j == s.size() / 2)
            {
                answer = s.size() - 1 - i;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.get();

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}