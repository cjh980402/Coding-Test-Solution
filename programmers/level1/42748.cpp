#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (const vector<int> &cmd : commands)
    {
        // array의 원소의 범위가 1~100으로 작기 때문에 counting sort로 풀어본다.
        int counts[101] = {0}; // 원소의 범위가 1~100이므로 101칸(0포함)짜리 배열을 선언한다.
        for (int i = cmd[0] - 1; i <= cmd[1] - 1; i++)
        {
            // counting sort를 적용하기 위한 계산
            counts[array[i]]++;
        }

        int sum = 0, kV = 0;
        for (int i = 0; i < 102; i++)
        {
            sum += counts[i];
            if (sum >= cmd[2])
            {
                // k번째 값이 탐색된 경우 값을 저장하고 반복을 종료한다.
                kV = i;
                break;
            }
        }
        answer.push_back(kV);
    }

    return answer;
}