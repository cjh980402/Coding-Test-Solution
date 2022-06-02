#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'stringConstruction' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int stringConstruction(const string &s)
{
    int answer = 0, count[26] = {0};

    for (char c : s)
    {
        if (count[c - 'a'] == 0)
        {
            answer++; // 이전에 읽은 글자가 아닌 경우 비용이 1만큼 필요하다.
        }
        count[c - 'a']++;
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

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}