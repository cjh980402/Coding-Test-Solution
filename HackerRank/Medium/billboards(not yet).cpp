#include <bits/stdc++.h>

using namespace std;

struct Profit
{
    long long value;
    int pos;
};

class CompareProfit
{
public:
    bool operator()(const Profit &t1, const Profit &t2)
    {
        return t1.value > t2.value;
    }
};

/*
 * Complete the 'billboards' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY revenue
 */
long long billboards(int k, const vector<int> &revenue)
{
    long long sum = accumulate(revenue.begin(), revenue.end(), 0LL);
    int n = revenue.size();
    if (k == n)
    {
        // 최대 광고판의 길이가 n과 동일하면 전체를 광고에 포함할 수 있음
        return sum;
    }

    priority_queue<Profit, vector<Profit>, CompareProfit> pq; // value가 작은 값이 앞에 있음

    for (int i = 0; i < n; i++)
    {
        if (i <= k)
        {
            pq.push({revenue[i], i});
        }
        else
        {
            Profit p = pq.top();
            while (p.pos < i - (k + 1))
            {
                pq.pop();
                p = pq.top();
            }
            pq.push({revenue[i] + p.value, i});
        }
    }

    Profit p = pq.top();
    while (p.pos < n - (k + 1))
    {
        pq.pop();
        p = pq.top();
    }
    return sum - p.value;
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