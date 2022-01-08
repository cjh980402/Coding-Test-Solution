#include <vector>

using namespace std;

int search(const vector<vector<int>> &picture, vector<vector<bool>> &searched, int i, int j)
{
    if (picture[i][j] == 0 || searched[i][j])
        return 0;
    int result = 1;        // picture[i][j] 1개
    searched[i][j] = true; // 방문 표시
    // 4방향 모두 탐색, 현재 위치와 색이 같은 경우 추가 진행 (재귀호출)
    if (i - 1 >= 0)
    { // 상
        if (picture[i - 1][j] == picture[i][j])
            result += search(picture, searched, i - 1, j);
    }
    if (i + 1 < picture.size())
    { // 하
        if (picture[i + 1][j] == picture[i][j])
            result += search(picture, searched, i + 1, j);
    }
    if (j - 1 >= 0)
    { // 좌
        if (picture[i][j - 1] == picture[i][j])
            result += search(picture, searched, i, j - 1);
    }
    if (j + 1 < picture[0].size())
    { // 우
        if (picture[i][j + 1] == picture[i][j])
            result += search(picture, searched, i, j + 1);
    }
    return result;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    vector<int> answer(2);                                    // [0]: 개수, [1]: 크기
    vector<vector<bool>> searched(m, vector<bool>(n, false)); // picture와 같은 형태의 방문 체크용 배열

    // 모든 영역에 대해 수행
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int area = search(picture, searched, i, j);
            if (area > 0)
            {                                                    // 유효한 영역인 경우
                answer[0]++;                                     // 개수 증가
                answer[1] = answer[1] < area ? area : answer[1]; // 최댓값 갱신
            }
        }
    }

    return answer;
}