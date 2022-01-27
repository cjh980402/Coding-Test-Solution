#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    // 0에서 n까지 가는 최소비용은 n에서 0까지 가는 최소비용과 동일 -> 역추적 이용
    for (; n; n /= 2)
    {
        if (n % 2)
        {
            n--;
            ans++;
        }
    }

    return ans;
}