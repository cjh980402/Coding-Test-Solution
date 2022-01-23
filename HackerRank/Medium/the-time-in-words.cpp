#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string toENGString(int n)
{
    string engs[31] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eightteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "half"};

    return engs[n];
}

string minuteString(string mid, int m)
{
    if (m % 15 == 0)
        return mid;
    else if (m == 1)
        return " minute" + mid;
    else
        return " minutes" + mid;
}

string timeInWords(int h, int m)
{
    if (m == 0)
    {
        string h_str = toENGString(h);
        return h_str + " o' clock";
    }
    else if (m <= 30)
    {
        string h_str = toENGString(h), m_str = toENGString(m);
        return m_str + minuteString(" past ", m) + h_str;
    }
    else
    {
        string h_str = toENGString(h + 1), m_str = toENGString(60 - m);
        return m_str + minuteString(" to ", m) + h_str;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

    fout << result << "\n";

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