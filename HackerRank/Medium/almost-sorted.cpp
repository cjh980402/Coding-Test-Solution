#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void almostSorted(vector<int> arr)
{
    vector<int> afterSorted(arr), unsortIndex;

    sort(afterSorted.begin(), afterSorted.end());

    // 정렬되지 않은 위치 인덱스 저장
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != afterSorted[i])
            unsortIndex.push_back(i);
    }

    if (unsortIndex.empty())
    {
        // 모두 정렬된 경우
        cout << "yes";
    }
    else if (unsortIndex.size() == 2)
    {
        // 2개만 정렬되지 않은 경우
        cout << "yes\nswap " << unsortIndex[0] + 1 << ' ' << unsortIndex[1] + 1;
    }
    else
    {
        // 그 외의 경우로 reverse 가능 유무를 판단한다.
        bool isPossible = true;
        for (int i = 0; isPossible && i <= unsortIndex.size() / 2; i++)
        {
            if (arr[unsortIndex[i]] != afterSorted[unsortIndex[unsortIndex.size() - 1 - i]])
                isPossible = false;
        }
        if (isPossible)
            cout << "yes\nreverse " << unsortIndex[0] + 1 << ' ' << unsortIndex.back() + 1;
        else
            cout << "no";
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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