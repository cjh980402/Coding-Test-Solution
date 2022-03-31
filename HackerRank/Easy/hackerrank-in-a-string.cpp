#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'hackerrankInString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string hackerrankInString(string s)
{
    const string target = "hackerrank";
    int targetI = 0; // 현재 찾아야할 target문자열 글자의 위치

    for (char c : s)
    {
        if (c == target[targetI])
        {
            targetI++; // 탐색이 완료됐으면 다음 글자 탐색
        }
    }

    return targetI == target.size() ? "YES" : "NO"; // 끝까지 탐색된 경우 YES 반환
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}