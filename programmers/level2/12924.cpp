#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = n % 2 ? 2 : 1; // 2개, 1개인 경우 계산

    // 그 외 경우 계산
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            if (i % 2)
                answer++;
            if (i != n / i && (n / i) % 2)
                answer++;
        }
    }

    return answer;
}