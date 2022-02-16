#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'billboards' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY revenue
 */
long long billboards(int k, vector<int> revenue)
{
    vector<vector<long long>> sum_list;
    for (int i = 0; i <= revenue.size() - k; i++)
    {
        long long sum = 0;
        for (int j = i; j < i + k; j++)
        {
            sum += revenue[j];
        }
        sum_list.push_back({i, i + k - 1, sum});
    }

    sort(sum_list.begin(), sum_list.end(), [](const vector<long long> &a, const vector<long long> &b)
         { return a[2] > b[2]; });

    return sum_list[0][2];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, k;
    cin >> n >> k;

    vector<int> revenue(n);

    for (int i = 0; i < n; i++)
    {
        cin >> revenue[i];
    }

    long long result = billboards(k, revenue);

    fout << result << "\n";

    fout.close();

    return 0;
}