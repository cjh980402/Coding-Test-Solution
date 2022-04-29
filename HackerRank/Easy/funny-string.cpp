#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'funnyString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string funnyString(const string &s)
{
    int len = s.size();
    bool isFunny = true;

    for (int i = 1; i < len; i++)
    {
        int leftDiff = abs(s[i] - s[i - 1]);                        // 원래 문자열의 차이 값
        int rightDiff = abs(s[len - 1 - i] - s[len - 1 - (i - 1)]); // 뒤집은 문자열의 차이 값

        if (leftDiff != rightDiff)
        {
            isFunny = false;
            break;
        }
    }

    return isFunny ? "Funny" : "Not Funny";
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

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}