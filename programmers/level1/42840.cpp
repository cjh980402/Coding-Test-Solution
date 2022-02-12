#include <vector>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<vector<int>> patterns = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}}; // 수포자의 패턴
    vector<int> answer;
    int counts[3] = {0}; // 수포자가 맞춘 정답 수
    int maxV = 0;        // 최대 정답 수

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < answers.size(); j++)
        {
            if (answers[j] == patterns[i][j % patterns[i].size()])
            {
                // 정답을 맞춘 경우 카운트 증가
                counts[i]++;
            }
        }

        if (maxV < counts[i])
        {
            // 카운트 최댓값 갱신
            maxV = counts[i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (maxV == counts[i])
        {
            // 최대 카운트값과 동일한 경우
            answer.push_back(i + 1);
        }
    }

    return answer;
}