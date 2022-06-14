#include <iostream>
#include <numeric>

using namespace std;

int main(void)
{
    // 입력의 범위를 고려하여 unsigned long long 사용
    unsigned long long A, B;
    cin >> A >> B;

    unsigned long long len = gcd(A, B); // 주어진 길이의 최대공약수만큼 1을 출력하면 답이 된다.
    for (unsigned long long i = 0; i < len; i++)
    {
        cout << '1';
    }

    return 0;
}