#include <vector>
#include <queue>
#include <utility>
using namespace std;

// 최단 거리를 구해야하므로 DFS 말고 BFS를 이용해야한다
int solution(vector<vector<int>> maps)
{
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    queue<pair<int, int>> bfsq;

    // 시작지점 체크하기
    bfsq.push(pair(0, 0));
    visited[0][0] = true;

    while (!bfsq.empty())
    {
        auto [r, c] = bfsq.front();
        bfsq.pop();
        // 각 방향에 대해 큐에 넣고 방문 표시하기
        // 상
        if (c > 0 && maps[r][c - 1] && !visited[r][c - 1])
        {
            bfsq.push(pair(r, c - 1));
            visited[r][c - 1] = true;
            maps[r][c - 1] = maps[r][c] + 1;
        }

        // 좌
        if (r > 0 && maps[r - 1][c] && !visited[r - 1][c])
        {
            bfsq.push(pair(r - 1, c));
            visited[r - 1][c] = true;
            maps[r - 1][c] = maps[r][c] + 1;
        }

        // 하
        if (c + 1 < maps[0].size() && maps[r][c + 1] && !visited[r][c + 1])
        {
            bfsq.push(pair(r, c + 1));
            visited[r][c + 1] = true;
            maps[r][c + 1] = maps[r][c] + 1;
        }

        // 우
        if (r + 1 < maps.size() && maps[r + 1][c] && !visited[r + 1][c])
        {
            bfsq.push(pair(r + 1, c));
            visited[r + 1][c] = true;
            maps[r + 1][c] = maps[r][c] + 1;
        }
    }

    // 맵 전체에 대해 탐색이 완료되었는데 진영에 미도달 했으면 진영의 값이 그대로 1임
    return maps.back().back() == 1 ? -1 : maps.back().back();
}