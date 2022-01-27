#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    while (1)
    {
        bool noSquare = true;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (board[i][j] && toupper(board[i][j]) == toupper(board[i + 1][j]) && toupper(board[i + 1][j]) == toupper(board[i + 1][j + 1]) && toupper(board[i][j + 1]) == toupper(board[i + 1][j + 1]))
                {
                    // 사각형 발견에 대한 플래그 변수 표기, 지워진 문자는 소문자로 변경
                    noSquare = false;
                    board[i][j] = tolower(board[i][j]);
                    board[i + 1][j] = tolower(board[i + 1][j]);
                    board[i][j + 1] = tolower(board[i][j + 1]);
                    board[i + 1][j + 1] = tolower(board[i + 1][j + 1]);
                }
            }
        }
        if (noSquare)
            break;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (islower(board[i][j]))
                {
                    answer++; // 현재 지워진 칸
                    int notErased = i - 1;
                    for (; notErased >= 0; notErased--)
                    {
                        if (islower(board[notErased][j]))
                            answer++; // 현재 칸보다 위에 있는 지워진 칸
                        else
                            break;
                    }
                    for (int k = 0; i - k >= 0; k++)
                    {
                        board[i - k][j] = notErased - k >= 0 ? board[notErased - k][j] : '\0';
                    }
                }
            }
        }
    }

    return answer;
}