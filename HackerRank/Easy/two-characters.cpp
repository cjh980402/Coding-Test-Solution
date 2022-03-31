#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int alternate(const string &s)
{
    int maxLen = 0;

    // 모든 두 글자 알파벳 조합에 대해 테스트
    for (int i = 0; i < 25; i++)
    {
        for (int j = 1; j < 26; j++)
        {
            string temp;
            bool isAlter = true;

            for (char c : s)
            {
                if (c == 'a' + i || c == 'a' + j)
                {
                    if (temp.back() == c)
                    {
                        // 같은 글자가 연속으로 발견된 경우 alternate가 아니므로 종료한다.
                        isAlter = false;
                        break;
                    }
                    else
                    {
                        temp += c;
                    }
                }
            }

            if (isAlter && temp.size() > 1)
            {
                // 같은 글자가 연속으로 오지 않고 길이가 1보다 크면 alternate이므로 최대 길이를 갱신한다.
                maxLen = max(maxLen, (int)temp.size());
            }
        }
    }

    return maxLen;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int l;
    cin >> l;
    cin.get();

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}