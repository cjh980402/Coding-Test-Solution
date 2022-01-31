#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q)
{
    bool invalid = true;

    // i*i의 오버플로우를 방지하기 위해 long long 사용
    for (long long i = p; i <= q; i++)
    {
        string square = to_string(i * i);
        int left = square.length() / 2 > 0 ? stoll(square.substr(0, square.length() / 2)) : 0; // left는 길이가 0인 문자열이 들어갈 수도 있으므로 예외처리를 한다.
        int right = stoll(square.substr(square.length() / 2));
        // Kaprekar number의 조건 검사
        if (left + right == i)
        {
            cout << i << ' ';
            invalid = false;
        }
    }

    if (invalid)
        cout << "INVALID RANGE";
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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