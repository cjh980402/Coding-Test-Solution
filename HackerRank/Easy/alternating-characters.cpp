#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'alternatingCharacters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int alternatingCharacters(const string &s)
{
    int answer = 0;
    char before = s[0];

    for (int i = 1; i < s.size(); i++)
    {
        if (before == s[i])
        {
            answer++; // 이전 글자와 같은 경우는 삭제 가능한 글자
        }
        before = s[i];
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

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}