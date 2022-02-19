#include <bits/stdc++.h>

using namespace std;

struct Profit
{
    long long value;
    int pos;
};

// 우선순위 큐에 비교함수로 사용하기 위해 ()연산자를 오버로딩한 클래스
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
    // 우선순위 큐에는 전체에서 조건 k를 만족하기 위해 제거할 요소들의 합이 담긴다.

    for (int i = 0; i <= n; i++)
    {
        if (i <= k)
        {
            pq.push({revenue[i], i}); // 각각 revenue[i]를 제외하는 경우에 대응된다.
        }
        else
        {
            // k+1 이내 거리에 있는 값이 작은 요소가 발견되면 반복을 멈춘다.
            while (pq.top().pos < i - (k + 1))
            {
                pq.pop(); // 현재 위치 i에서 k+1보다 멀리 떨어진 값이 작은 요소들을 제거한다.
            }
            if (i < n)
            {
                pq.push({revenue[i] + pq.top().value, i}); // revenue[i]와 k+1 이내 거리에 있는 값이 작은 요소를 제외하는 경우에 대응된다.
            }
        }
    }

    return sum - pq.top().value; // 제거할 요소들의 합 중 가장 작은 값을 뺀 값을 반환한다.
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