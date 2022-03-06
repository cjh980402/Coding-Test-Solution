#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'workbook' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY arr
 */
int workbook(int n, int k, const vector<int> &arr)
{
    int answer = 0, page = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int nowStart = 1, nowEnd; nowStart <= arr[i - 1]; nowStart = nowEnd + 1)
        {
            page++;
            nowEnd = min(nowStart + k - 1, arr[i - 1]); // 현재 페이지의 마지막 문제 계산
            if (nowStart <= page && page <= nowEnd)
            {
                answer++; // special problem: 문제가 있는 페이지와 문제의 번호가 같은 경우
            }
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = workbook(n, k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}