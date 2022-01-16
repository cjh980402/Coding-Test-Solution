#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (const vector<string> &place : places)
    {
        int isCorrect = 1;

        for (int i = 0; isCorrect && i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (place[i][j] == 'P')
                {
                    if ((i > 0 && place[i - 1][j] == 'P') || (i < 4 && place[i + 1][j] == 'P') || (j > 0 && place[i][j - 1] == 'P') || (j < 4 && place[i][j + 1] == 'P')                                                                                                            // 이 4가지 경우는 상하좌우에 붙어있는 칸
                        || (i > 1 && place[i - 2][j] == 'P' && place[i - 1][j] != 'X') || (i < 3 && place[i + 2][j] == 'P' && place[i + 1][j] != 'X') || (j > 1 && place[i][j - 2] == 'P' && place[i][j - 1] != 'X') || (j < 3 && place[i][j + 2] == 'P' && place[i][j + 1] != 'X') // 이 4가지 경우는 상하좌우로 2칸씩 떨어진 칸
                        || (i > 0 && j > 0 && place[i - 1][j - 1] == 'P' && (place[i - 1][j] != 'X' || place[i][j - 1] != 'X')) || (i < 4 && j < 4 && place[i + 1][j + 1] == 'P' && (place[i + 1][j] != 'X' || place[i][j + 1] != 'X')) || (i > 0 && j < 4 && place[i - 1][j + 1] == 'P' && (place[i - 1][j] != 'X' || place[i][j + 1] != 'X')) || (i < 4 && j > 0 && place[i + 1][j - 1] == 'P' && (place[i + 1][j] != 'X' || place[i][j - 1] != 'X')))
                    { // 이 4가지는 대각선에 있는 칸
                        isCorrect = 0;
                        break;
                    }
                }
            }
        }

        answer.push_back(isCorrect);
    }

    return answer;
}