#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int lilysHomework(const vector<int> &arr)
{
    int ascending = 0, descending = 0;
    vector<int> asc(arr), desc(arr);

    sort(asc.begin(), asc.end(), [&](int a, int b)
         {
        if (a < b)
            ascending++;
        return a < b; });

    sort(desc.begin(), desc.end(), [&](int a, int b)
         {
        if (a > b)
            descending++;
        return a > b; });

    return min(ascending, descending);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
