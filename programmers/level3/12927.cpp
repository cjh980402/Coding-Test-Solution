#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works)
{
    // 기본적인 방법: n을 1씩 감소시킬때마다 최댓값에서 1씩 감소
    long long answer = 0;

    priority_queue<int> pq(works.begin(), works.end()); // O(k*logk)
    // 각 연산 후에 최댓값을 찾는 것이 핵심
    // 우선순위 큐를 사용했기 때문에 top은 항상 최댓값이다
    while (n--)
    {
        if (!pq.top())
            break; // 최댓값이 0일땐 모두 0이므로 바로 작업 종료
        int t = pq.top();
        pq.pop();       // O(logk)
        pq.push(t - 1); // O(logk)
    }

    // O(k*logk)
    while (!pq.empty())
        answer += pq.top() * pq.top(), pq.pop();

    return answer;
}