#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0, maxD = 0;
    vector<vector<int>> edges(n);
    queue<pair<int, int>> bfsq;
    vector<int> dist(n, -1);

    // 간선정보 파싱
    for (const vector<int> &e : edge)
    {
        edges[e[0] - 1].push_back(e[1] - 1);
        edges[e[1] - 1].push_back(e[0] - 1);
    }

    // BFS를 이용한 거리 계산
    dist[0] = 0;
    bfsq.push(pair(0, dist[0]));

    while (!bfsq.empty())
    {
        auto [now, nowCost] = bfsq.front();
        bfsq.pop();

        for (int i : edges[now])
        {
            if (dist[i] == -1) // 거리 최댓값 갱신, 미방문 노드를 큐에 넣기
                maxD = max(maxD, dist[i] = nowCost + 1), bfsq.push(pair(i, dist[i]));
        }
    }

    for (int d : dist)
    {
        if (maxD == d)
            answer++;
    }

    return answer;
}