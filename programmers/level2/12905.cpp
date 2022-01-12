#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    // board의 값을 변경하여 bottom-up DP로 문제를 푼다.
    int answer = board[0][0]; // 첫 값을 초기값으로 사용

    for (int i = 1; i < board.size() - answer; i++)
    {
        for (int j = 1; j < board[i].size() - answer; j++)
        {
            if (board[i][j])
            { // 현재 값이 1인 경우
                board[i][j] = 1 + min(board[i - 1][j], min(board[i][j - 1], board[i - 1][j - 1]));
                // bottom-up DP의 요소: 이전 단계들에서 계산된 값을 이용해 현재 단계 값을 계산
                // 세 방향의 이전 단계 값에서 최소값을 사용하는 이유: 1이 끊어진 경우에 대응 가능
                if (answer < board[i][j])
                    answer = board[i][j]; // 최대 길이로 값 갱신
            }
        }
    }

    return answer * answer;
}