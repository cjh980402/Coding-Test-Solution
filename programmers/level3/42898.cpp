#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    vector<vector<int>> land(m, vector<int>(n, -1));

    // 집 표시
    land[0][0] = 1;
    // 침수 지역은 도달 불가능이므로 0으로 표시
    for (const vector<int> &p : puddles)
        land[p[0] - 1][p[1] - 1] = 0;
    // 초기값, 침수 지역을 건너뛰고 이전 값을 가져오므로 침수 지역 너머는 모두 0이 됨
    for (int i = 1; i < m; i++)
        if (land[i][0] != 0)
            land[i][0] = land[i - 1][0];
    for (int i = 1; i < n; i++)
        if (land[0][i] != 0)
            land[0][i] = land[0][i - 1];

    // 바텀업 DP 방식
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            // 침수 지역이 아닌 경우 값 계산 수행
            if (land[i][j] != 0)
            {
                int left = land[i - 1][j];
                int up = land[i][j - 1];
                land[i][j] = (left + up) % 1000000007;
            }
        }
    }

    return land.back().back();
}