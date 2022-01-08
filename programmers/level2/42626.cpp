#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.size() > 1 && pq.top() < K)
    {
        int min = pq.top();
        pq.pop();
        int nextMin = pq.top();
        pq.pop();

        int mix = min + nextMin * 2;
        pq.push(mix);
        answer++;
    }

    return pq.top() < K ? -1 : answer;
}