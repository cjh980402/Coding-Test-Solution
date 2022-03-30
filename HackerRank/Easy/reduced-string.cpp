#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string superReducedString(const string &s)
{
    string before(s), answer;

    while (1)
    {
        for (int i = 0; i < before.length();)
        {
            if (before[i] != before[i + 1])
            {
                answer += before[i]; // 다음 글자와 다른 경우 현재 글자를 추가한다.
                i++;
            }
            else
            {
                i += 2; // 다음 글자와 같은 경우 둘 다 추가하지 않는다. -> answer에서 pair가 제거된다.
            }
        }
        if (before == answer)
        {
            break; // pair 없애기를 해도 결과가 같으면 반복 종료
        }
        before = answer;
        answer.clear();
    }

    return answer.empty() ? "Empty String" : answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}