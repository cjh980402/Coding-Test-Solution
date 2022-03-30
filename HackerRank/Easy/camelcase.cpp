#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int camelcase(const string &s)
{
    int answer = 1; // 최소 1개의 단어가 존재

    for (int i = 1; i < s.length(); i++)
    {
        if (isupper(s[i]))
            answer++; // 첫 단어 이후는 모두 대문자로 시작
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}