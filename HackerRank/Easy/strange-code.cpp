#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'strangeCounter' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER t as parameter.
 */
long long strangeCounter(long long t)
{
    long long sum = 0, init = 3; // sum은 이전 구간까지의 누적합, init은 현재 구간의 초기 카운트값

    // t가 포함되는 구간 탐색
    while (sum + init < t)
    {
        sum += init;
        init *= 2; // 2배씩 증가
    }

    return init - (t - (sum + 1)); // sum + 1은 현재 구간의 초기 시간값
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long long t;
    cin >> t;

    long long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}