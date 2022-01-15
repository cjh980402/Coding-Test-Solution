#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<int> board(rows * columns);
    for (int i = 0; i < board.size(); i++)
        board[i] = i + 1;

    for (const vector<int> &q : queries)
    {
        int r1 = q[0] - 1, c1 = q[1] - 1, r2 = q[2] - 1, c2 = q[3] - 1;
        int first = board[r1 * columns + c1];
        int nowMin = first;

        // 좌측
        for (int i = r1 + 1; i <= r2; i++)
            nowMin = min(nowMin, board[(i - 1) * columns + c1] = board[i * columns + c1]);
        // 하단
        for (int i = c1 + 1; i <= c2; i++)
            nowMin = min(nowMin, board[r2 * columns + i - 1] = board[r2 * columns + i]);
        // 우측
        for (int i = r2 - 1; i >= r1; i--)
            nowMin = min(nowMin, board[(i + 1) * columns + c2] = board[i * columns + c2]);
        // 상단
        for (int i = c2 - 1; i >= c1; i--)
            nowMin = min(nowMin, board[r1 * columns + i + 1] = board[r1 * columns + i]);

        board[r1 * columns + c1 + 1] = first;
        answer.push_back(nowMin);
    }

    return answer;
}