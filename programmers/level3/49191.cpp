#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
    // 플로이드-워셜 알고리즘(모든 정점간의 최단 경로 탐색)의 변형으로 풀이 가능
    int answer = 0, INF = 1000000;
    vector<vector<int>> G(n, vector<int>(n, INF));

    // 각 선수간 승패 초기값을 대입한다.
    // [A, B]에 대해 G[A][B] = 1(A가 B한테 승리), G[B][A] = -1(B가 A한테 패배)
    for (const vector<int> &v : results)
    {
        G[v[0] - 1][v[1] - 1] = 1;
        G[v[1] - 1][v[0] - 1] = -1;
    }
    for (int i = 0; i < n; i++)
        G[i][i] = 0;

    // 가능한 모든 중개 경로에 대해서 검토하는 것이 플로이드-워셜 알고리즘
    // k: 거쳐가는 선수
    for (int k = 0; k < n; k++)
    {
        // i: 출발 선수
        for (int i = 0; i < n; i++)
        {
            // j: 도착 선수
            for (int j = 0; j < n; j++)
            {
                // 거리 갱신 대신 승패여부를 파악 후 갱신
                // i가 k를 이기고 k가 j를 이기면 i는 j를 이김
                if (G[i][k] == 1 && G[k][j] == 1)
                {
                    G[i][j] = 1;
                }
                // i가 k한테 지고 k가 j한테 지면 i는 j한테 짐
                else if (G[i][k] == -1 && G[k][j] == -1)
                {
                    G[i][j] = -1;
                }
            }
        }
    }

    // 순위를 구할 수 있는 선수(모든 선수와의 승패가 명확한 경우) 탐색
    for (const vector<int> &g : G)
    {
        int count = 0;
        for (int i : g)
        {
            if (i != INF)
                count++;
        }
        if (count == n)
            answer++;
    }

    return answer;
}