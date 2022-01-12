#include <vector>

using namespace std;

int realPosition(int i, int j)
{
    // 2차원 좌표 -> 실제 1차원 좌표로 변환
    return i * (i + 1) / 2 + j;
}

vector<int> solution(int n)
{
    vector<int> answer(n * (n + 1) / 2);

    for (int edge = 0, start = 1; n >= 1; n -= 3, edge++)
    {
        // 각 단계마다 1개의 껍질을 채워주는 반복문
        int r = 2 * edge, c = edge;         // 껍질의 시작지점의 좌표
        answer[realPosition(r, c)] = start; // n이 1인 경우 대비

        for (int i = r; i < r + n - 1; i++)
            answer[realPosition(i, c)] = start++;

        r += n - 1;
        for (int j = c; j < c + n - 1; j++)
            answer[realPosition(r, j)] = start++;

        c += n - 1;
        for (int i = r, j = c; i > 2 * edge; i--, j--)
            answer[realPosition(i, j)] = start++;
    }

    return answer;
}