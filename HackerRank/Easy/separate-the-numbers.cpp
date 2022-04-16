#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */
void separateNumbers(const string &s)
{
    // 2개 이상 연속돼야 하므로 len의 최대 길이는 s의 길이의 절반
    for (int len = 1; len <= s.size() / 2; len++)
    {
        string before = s.substr(0, len); // len 글자로 시작할 때의 처음 등장하는 숫자
        bool isPossible = true;

        for (int i = len; i < s.size(); i += before.size())
        {
            string now = to_string(stoll(before) + 1); // 오버플로우를 방지하기 위해 stoll 사용, 현재 단계에서 나와야할 숫자

            if (s.substr(i, now.size()) == now)
            {
                // 그 다음 문자열이 나와야할 숫자와 같으면 반복 진행
                before = now;
            }
            else
            {
                // 같지 않으면 반복 종료
                isPossible = false;
                break;
            }
        }

        if (isPossible)
        {
            cout << "YES " << s.substr(0, len) << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int q;
    cin >> q;
    cin.get();

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}