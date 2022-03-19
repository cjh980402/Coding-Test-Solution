#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'bigSorting' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */
vector<string> bigSorting(const vector<string> &unsorted)
{
    vector<string> sorted(unsorted);

    // 길이가 같은 경우: 문자열의 대소와 숫자의 대소가 같다.
    // 길이가 다른 경우: 길이가 짧으면 값이 작은 숫자이다.
    sort(sorted.begin(), sorted.end(), [](const string &a, const string &b)
         { return a.size() == b.size() ? (a < b) : (a.size() < b.size()); });

    return sorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++)
    {
        cin >> unsorted[i];
    }

    vector<string> result = bigSorting(unsorted);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i] << "\n";
    }

    fout.close();

    return 0;
}