#include <vector>
#include <utility>

using namespace std;

int solution(int m, int n, vector<vector<int>> city_map)
{
    vector<vector<pair<int, int>>> city(m, vector<pair<int, int>>(n)); // 원소의 first는 왼쪽에서 온 점수, second는 위쪽에서 온 점수

    // 시작지점 표시
    city[0][0] = pair(1, 1);
    // 초기값, 진입 불가능 지역을 건너뛰고 이전 값을 가져오므로 진입 불가능 지역 너머는 모두 0이 됨
    for (int i = 1; i < m; i++)
        if (city_map[i][0] != 1)
            city[i][0].second = city[i - 1][0].second;
    for (int i = 1; i < n; i++)
        if (city_map[0][i] != 1)
            city[0][i].first = city[0][i - 1].first;

    // 바텀업 DP 방식
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            // 진입 불가능 지역이 아닌 경우 값 계산 수행
            if (city_map[i][j] != 1)
            {
                // 이전 지역의 값이 0이면 방향의 제한이 없지만 2인 경우는 왼쪽에서 오던 차(first)는 오른쪽으로만, 위에서 오던 차(second)는 아래쪽으로만 진행 가능하다.
                int left = (city_map[i][j - 1] == 0) ? (city[i][j - 1].first + city[i][j - 1].second) % 20170805 : (city[i][j - 1].first);
                int up = (city_map[i - 1][j] == 0) ? (city[i - 1][j].first + city[i - 1][j].second) % 20170805 : (city[i - 1][j].second);
                city[i][j].first = left;
                city[i][j].second = up;
            }
        }
    }

    const auto &[left, up] = city.back().back();

    return (left + up) % 20170805;
}