#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */
string happyLadybugs(string b)
{
    unordered_map<char, int> count;
    bool notHappy = false;

    count[b[0]]++;
    if (b.size() > 1)
        count[b.back()]++; // b가 1글자면 첫 글자와 마지막 글자가 같으므로 확인을 해야한다.
    for (int i = 1; i < b.size() - 1; i++)
    {
        count[b[i]]++;
        if (b[i - 1] != '_' && b[i] != '_' && b[i + 1] != '_' && b[i - 1] != b[i] && b[i + 1] != b[i])
        {
            notHappy = true; // 빈 칸을 제외하고 앞 뒤로 같은 글자가 없는 경우는 notHappy 상태
        }
    }

    for (const auto &p : count)
    {
        if (p.first != '_' && p.second == 1)
        {
            return "NO"; // 글자가 하나만 있는 경우는 happy 상태가 불가능함
        }
    }

    return notHappy && count['_'] < 1 ? "NO" : "YES"; // notHappy 상태에서 빈 칸이 없어서 이동할 수 없으면 NO 반환
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;

    for (int g_itr = 0; g_itr < g; g_itr++)
    {
        int n;
        cin >> n;
        cin.get(); // 정수 입력받은 후 남아있는 개행 제거

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}