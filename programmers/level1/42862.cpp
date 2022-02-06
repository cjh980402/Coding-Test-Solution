#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> count(n, 1); // 처음에는 모두 1벌씩 소지

    for (int l : lost)
    {
        // 체육복을 잃어버린 학생 계산
        count[l - 1]--;
    }
    for (int r : reserve)
    {
        // 여벌의 체육복을 가진 학생 계산
        count[r - 1]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (count[i] > 0)
        {
            // 체육복을 가지고 있는 학생
            answer++;
        }
        else
        {
            // 체육복이 없는 학생
            if (i > 0 && count[i - 1] == 2)
            {
                // 이전 학생한테 여벌이 있는 경우
                answer++;
                count[i - 1]--;
                count[i]++;
            }
            else if (i + 1 < n && count[i + 1] == 2)
            {
                // 다음 학생한테 여벌이 있는 경우
                answer++;
                count[i + 1]--;
                count[i]++;
            }
        }
    }

    return answer;
}