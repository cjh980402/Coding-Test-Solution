#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'beautifulBinaryString' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING b as parameter.
 */
int beautifulBinaryString(const string &b)
{
    int answer = 0;

    for (int i = 0; i < b.size(); i++)
    {
        // 겹치지 않는 위치에 있는 010마다 한 자리를 변경할 때가 최소 횟수이다.
        if (b.substr(i, 3) == "010")
        {
            answer++;
            i += 2; // 010의 끝 지점으로 커서 이동
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

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}