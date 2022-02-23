#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'minimumDistances' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
int minimumDistances(const vector<int> &a)
{
    unordered_map<int, vector<int>> duplication;

    for (int i = 0; i < a.size(); i++)
    {
        duplication[a[i]].push_back(i);
    }

    int min = a.size();

    for (const auto &p : duplication)
    {
        if (p.second.size() < 2)
            continue;
        for (int i = 1; i < p.second.size(); i++)
        {
            if (min > p.second[i] - p.second[i - 1])
                min = p.second[i] - p.second[i - 1];
        }
    }

    return min == a.size() ? -1 : min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int result = minimumDistances(a);

    fout << result << "\n";

    fout.close();

    return 0;
}