#include <vector>

using namespace std;

int solution(int n, vector<int> money)
{
    // money의 정렬상태는 문제풀이에 영향을 주지 않는다.
    // 효율적으로 풀기위해 DP를 사용한다.
    vector<int> cache(n + 1, 0);

    cache[0] = 1; // 0원을 만드는 경우는 아무것도 선택안하는 1가지 경우밖에 없다.

    // 바텀업 DP 방식으로 이전에 계산된 값들에 m원을 추가로 사용하는 방식으로 계산을 한다.
    for (int m : money)
    {
        for (int i = m; i <= n; i++)
        {
            // i원을 만들 때 m원을 사용하는 경우, m원을 하나만 사용하고 나머지 잔액 계산
            // (i-m)은 i보다 작으므로 이미 이전에 계산된 값이고 여기서도 m원이 사용되었을 수 있기 때문에 m원을 여러개 사용하는 경우는 자동으로 고려된다.
            cache[i] = (cache[i] + cache[i - m]) % 1000000007;
        }
    }

    return cache.back();
}