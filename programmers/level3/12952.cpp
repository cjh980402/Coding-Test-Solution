#include <vector>

using namespace std;

int dfs(vector<vector<int>> &board, int now)
{
    int n = board.size();
    if (now == n)
        return 1; // 끝 행까지 도달한 경우

    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        // board[now][i]가 공격을 받는 범위인 경우 건너뜀
        if (board[now][i])
            continue;

        // 공격 가능한 범위 표시, 이전 행들은 이미 검토가 끝났으므로 now부터 진행가능
        for (int j = now; j < n; j++)
        {
            board[j][i]++; // 같은 열
            if (0 <= i - now + j && i - now + j < n)
                board[j][i - now + j]++; // 좌상향, 우하향 대각선
            if (0 <= i + now - j && i + now - j < n)
                board[j][i + now - j]++; // 좌하향, 우상향 대각선
        }

        answer += dfs(board, now + 1);

        // 공격 범위 표시 제거
        for (int j = now; j < n; j++)
        {
            board[j][i]--; // 같은 열
            if (0 <= i - now + j && i - now + j < n)
                board[j][i - now + j]--; // 좌상향, 우하향 대각선
            if (0 <= i + now - j && i + now - j < n)
                board[j][i + now - j]--; // 좌하향, 우상향 대각선
        }
    }

    return answer;
}

int solution(int n)
{
    int answer = 0;
    vector<vector<int>> board(n, vector<int>(n, 0));

    answer = dfs(board, 0);

    return answer;
}