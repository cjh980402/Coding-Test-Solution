#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<vector<int>> count(N, vector<int>(10, 0));

    for (int i = 1; i < 10; i++)
    {
        count[0][i] = 1;
    }

    // 바텀업 DP, i는 자리수, j는 마지막 자리의 숫자
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // 각각 유효한 자리수인 경우 값을 계산한다.
            if (j - 1 >= 0)
            {
                count[i + 1][j - 1] = (count[i + 1][j - 1] + count[i][j]) % 1000000000;
            }
            if (j + 1 < 10)
            {
                count[i + 1][j + 1] = (count[i + 1][j + 1] + count[i][j]) % 1000000000;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum = (sum + count[N - 1][i]) % 1000000000;
    }

    cout << sum;

    return 0;
}