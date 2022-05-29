#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int anagram(const string &s)
{
    int len = s.size();
    if (len % 2)
    {
        return -1; // 길이가 홀수여서 균등하게 자를 수 없는 경우는 -1 반환
    }

    int count1[26] = {0}, count2[26] = {0};
    for (int i = 0; i < len / 2; i++)
    {
        count1[s[i] - 'a']++; // 첫번째 부분문자열에 존재하는 각 문자의 개수
    }
    for (int i = len / 2; i < len; i++)
    {
        count2[s[i] - 'a']++; // 두번째 부분문자열에 존재하는 각 문자의 개수
    }

    int answer = 0;
    for (int i = 0; i < 26; i++)
    {
        answer += abs(count2[i] - count1[i]); // 두번째 문자열에 더 많이 존재하는 문자는 +, 첫번째 문자열에 더 많이 존재하는 문자는 -
    }

    return answer / 2; // 위와 같은 계산에서 바꿀 1개의 문자에 대해 2개가 카운트되기 때문에 2로 나눠준다.
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

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
