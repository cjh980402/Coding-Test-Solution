#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int count[100][10][1024] = {0};
    // 첫번째 인덱스: 자리수, 두번째 인덱스: 마지막 자리의 숫자, 세번째 인덱스: 사용한 숫자 표시한 플래그

    for (int i = 1; i < 10; i++)
    {
        count[0][i][1 << i] = 1;
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 1024; k++)
            {
                // 각각 유효한 자리수인 경우 값을 계산한다.
                // k | (1 << n)은 플래그 변수 k의 n번째 비트를 활성화한 값을 반환한다.
                if (j - 1 >= 0)
                {
                    count[i + 1][j - 1][k | (1 << (j - 1))] = (count[i + 1][j - 1][k | (1 << (j - 1))] + count[i][j][k]) % 1000000000;
                }
                if (j + 1 < 10)
                {
                    count[i + 1][j + 1][k | (1 << (j + 1))] = (count[i + 1][j + 1][k | (1 << (j + 1))] + count[i][j][k]) % 1000000000;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum = (sum + count[N - 1][i][1023]) % 1000000000; // 3번째 인덱스가 1023인 경우는 0부터 9까지 모든 숫자를 사용한 경우의 개수가 담겨있다.
    }

    cout << sum;

    return 0;
}