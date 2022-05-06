#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'theLoveLetterMystery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int theLoveLetterMystery(const string &s)
{
    int answer = 0, len = s.size();

    for (int i = 0; i < len / 2; i++)
    {
        answer += abs(s[i] - s[len - 1 - i]); // 회문을 만들기 위한 거리 = 매칭되는 위치의 두 문자의 차이의 절댓값
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

        int result = theLoveLetterMystery(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}