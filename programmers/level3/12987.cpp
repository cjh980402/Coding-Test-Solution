#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    // A와 B의 내용을 담은 우선순위 큐 생성
    priority_queue<int> pqA(A.begin(), A.end());
    priority_queue<int> pqB(B.begin(), B.end());

    // 우선순위 큐를 사용했으므로 최댓값을 가져오기 쉽고 삭제도 빠르게 가능하다.
    while (!pqA.empty())
    {
        int topA = pqA.top(), topB = pqB.top();
        pqA.pop(); // O(logn)
        // 현재 B의 최댓값이 A의 최댓값을 이길 수 있는 경우 매칭을 바로 수행, 그렇지 않은 경우 A의 다음 최댓값과 매칭을 해본다.
        if (topB > topA)
        {
            answer++;
            pqB.pop(); // O(logn)
        }
    }

    return answer;
}