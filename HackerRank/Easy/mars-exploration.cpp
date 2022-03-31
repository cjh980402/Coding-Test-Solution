#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int marsExploration(const string &s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); i += 3)
    {
        // SOS에 해당하는 글자인지 검사한다.
        if (s[i] != 'S')
        {
            answer++;
        }
        if (s[i + 1] != 'O')
        {
            answer++;
        }
        if (s[i + 2] != 'S')
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}