#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'absolutePermutation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */

vector<int> absolutePermutation(int n, int k)
{
    vector<int> answer;
    vector<bool> used(n); // 이전에 사용되었는지 검토하기 위한 플래그 배열

    for (int i = 1; i <= n; i++)
    {
        // abs(pos[i] - i) == k이므로 pos[i]는 i-k 또는 i+k 중 하나이다.
        // 사전순으로 가장 작은 순열을 찾아 반환해야하므로 i-k를 우선적으로 검사한다.
        if (1 <= i - k && i - k <= n && !used[i - k - 1])
            answer.push_back(i - k), used[i - k - 1] = true;
        else if (1 <= i + k && i + k <= n && !used[i + k - 1])
            answer.push_back(i + k), used[i + k - 1] = true;
        else
            break; // i-k와 i+k 둘 다 불가능한 경우는 absolute permutation이 없는 경우
    }

    return answer.size() == n ? answer : vector<int>{-1}; // 반복문 도중에 break가 되면 absolute permutation이 없는 경우이므로 {-1} 반환
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        vector<int> result = absolutePermutation(n, k);

        for (size_t i = 0; i < result.size(); i++)
        {
            fout << result[i];

            if (i != result.size() - 1)
            {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}