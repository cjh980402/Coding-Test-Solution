#include <vector>
#include <queue>
#include <utility>
using namespace std;

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> bfsq; // 힙으로 구현된 우선순위 큐(작은 값이 앞에 있음)
    vector<int> dist(N, 2147483647);                                  // 시작점으로부터의 거리 정보 저장
    vector<vector<int>> cost(N, vector<int>(N, 2147483647));          // 간선 정보 저장

    // 간선 정보를 저장하는 코드
    for (const vector<int> &r : road)
    {
        int start = r[0] - 1;
        int dest = r[1] - 1;
        int time = r[2];
        // 같은 지점을 연결하는 도로가 여러개인 경우 값이 작은 도로를 사용한다
        if (time < cost[start][dest])
            cost[start][dest] = cost[dest][start] = time;
    }
    for (int i = 0; i < N; i++)
    {
        cost[i][i] = 0;
    }

    // 다익스트라 알고리즘 코드
    dist[0] = 0;
    bfsq.push(pair(0, dist[0]));

    while (!bfsq.empty())
    {
        auto [now, nowCost] = bfsq.top();
        bfsq.pop();

        for (int i = 0; i < N; i++)
        {
            if (cost[now][i] != 2147483647 && dist[i] > nowCost + cost[now][i])
            {
                dist[i] = nowCost + cost[now][i]; // 더 작은 값으로 거리 갱신
                bfsq.push(pair(i, dist[i]));
            }
        }
    }

    for (int d : dist)
    {
        if (d <= K)
            answer++;
    }

    return answer;
}