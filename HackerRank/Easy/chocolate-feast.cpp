#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'chocolateFeast' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c
 *  3. INTEGER m
 */
int chocolateFeast(int n, int c, int m)
{
    int answer = 0, bar = n / c, wrap = 0;

    while (1)
    {
        answer += bar; // 총 먹은 바의 개수
        wrap += bar;   // 바를 먹고 남은 포장지의 개수
        if (wrap < m)
            break; // 포장지를 새로운 바로 교환하기에 부족한 경우 바로 종료

        bar = wrap / m; // 포장지를 새로운 바로 교환
        wrap %= m;      // 남은 포장지의 개수
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        int n, c, m;
        cin >> n >> c >> m;

        int result = chocolateFeast(n, c, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}