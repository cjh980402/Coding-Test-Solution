#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> count(N + 1, 1000000);

    count[0] = count[1] = 0;

    // 바텀업 DP
    for (int i = 1; i <= N; i++)
    {
        if (i + 1 <= N)
        {
            // 1을 감소시키는 경우
            count[i + 1] = min(count[i] + 1, count[i + 1]);
        }
        if (2 * i <= N)
        {
            // 2로 나누어 떨어지는 경우
            count[2 * i] = min(count[i] + 1, count[2 * i]);
        }
        if (3 * i <= N)
        {
            // 3으로 나누어 떨어지는 경우
            count[3 * i] = min(count[i] + 1, count[3 * i]);
        }
    }

    cout << count[N];

    return 0;
}