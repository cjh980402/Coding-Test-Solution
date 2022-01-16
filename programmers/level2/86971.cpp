#include <utility>
#include <vector>
#include <cstdlib>

using namespace std;

int countSet(const vector<vector<pair<int, int>>> &wireList, vector<int> &visit, int now, int exclude)
{
    int count = 1;

    visit[now] = true;
    for (const pair<int, int> &wire : wireList[now])
    {
        if (visit[wire.first] || wire.second == exclude)
            continue;
        count += countSet(wireList, visit, wire.first, exclude);
    }

    return count;
}

int solution(int n, vector<vector<int>> wires)
{
    int minDiff = 2147483647;
    vector<vector<pair<int, int>>> wireList(n);

    for (int i = 0; i < n - 1; i++)
    {
        // 시작 정점, 도착 정점에 대해 모두 간선 정보를 추가해준다.
        wireList[wires[i][0] - 1].push_back(pair(wires[i][1] - 1, i));
        wireList[wires[i][1] - 1].push_back(pair(wires[i][0] - 1, i));
    }

    for (int i = 0; i < n - 1; i++)
    {
        // i번째 간선을 제외한 경우 계산 -> wires[i][0]과 wires[i][1]이 다른 집합
        vector<int> visit(n, false);
        // 1개의 집합의 크기만 계산하면 나머지도 구해짐 (count와 n-count)
        int diff = abs(n - 2 * countSet(wireList, visit, wires[i][0] - 1, i));
        if (diff < minDiff)
            minDiff = diff;
    }

    return minDiff;
}