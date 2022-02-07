#include <vector>

using namespace std;

int solution(int n)
{
    // 특정 범위(1~n) 내에 소수를 찾아야하므로 에라토스테네스의 체를 사용한다.
    int answer = 0;
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false; // 0과 1은 소수가 아님

    // i*i의 오버플로우를 방지하기 위해 i와 j는 long long으로 선언
    for (long long i = 2; i <= n; i++)
    {
        if (!prime[i])
            continue;

        answer++; // i는 소수임

        // j가 i*i부터 시작하는 이유는 i*1부터 i*(i-1)까지는 이전의 i값들에서 계산되었기 때문이다.
        for (long long j = i * i; j <= n; j += i)
        {
            prime[j] = false; // j는 i의 배수이므로 소수가 아님
        }
    }

    return answer;
}