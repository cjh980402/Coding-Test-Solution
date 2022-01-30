#include <vector>

using namespace std;

// 유클리드 호제법을 사용한 최대공약수 구하기
int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

vector<int> solution(int n, int m)
{
    int gcdNM = gcd(n, m);
    // 최소공배수는 두 수의 곱을 최대공약수로 나눈 값과 같다.
    return {gcdNM, (n * m) / gcdNM};
}