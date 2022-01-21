#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
    if (n > s)
        return {-1};

    // 합이 제일 큰 경우는 각 원소가 최대한 균등한 경우임
    int div = s / n;
    int mod = s % n;
    vector<int> answer(n, div); // 우선 div만큼 n개 분배한다.
    for (int i = n - mod; i < n; i++)
        answer[i]++; // 나머지인 mod또한 1씩 균등 분배한다.

    // 위 과정을 거치면 answer는 이미 정렬된 상태
    return answer;
}