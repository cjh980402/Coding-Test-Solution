#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gemstones' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY arr as parameter.
 */
int gemstones(const vector<string> &arr)
{
    int answer = 0;
    int count[26] = {0};

    for (const string &s : arr)
    {
        bool isCounted[26] = {false}; // 같은 rock에서의 중복 방지용도
        for (char c : s)
        {
            if (!isCounted[c - 'a'])
            {
                // 개수 증가 + 중복 방지 체크
                count[c - 'a']++;
                isCounted[c - 'a'] = true;
            }
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] == arr.size())
        {
            answer++; // i번째 알파벳은 모든 rock에서 등장
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.get();

    vector<string> arr(n);

    for (int i = 0; i < n; i++)
    {
        getline(cin, arr[i]);
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
