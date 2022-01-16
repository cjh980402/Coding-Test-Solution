#include <vector>
#include <bitset>

using namespace std;

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    bitset<500> finish;

    for (int time = 0; finish.count() < jobs.size();)
    {
        int min = 2147483647, minIndex = -1;
        for (int i = 0; i < jobs.size(); i++)
        {
            // 이미 요청이 들어온 것 중 수행시간이 제일 작은거 고르기
            if (!finish[i] && jobs[i][0] <= time && min > jobs[i][1])
            {
                min = jobs[i][1];
                minIndex = i;
            }
        }
        if (minIndex == -1)
        {
            // 현재 요청이 들어온게 없는 경우는 다음 시간으로 넘기기 -> 1씩 증가하므로 제일 처음들어온 요청을 먼저 만나게 됨
            time++;
            continue;
        }

        finish[minIndex] = 1;
        answer += ((time += jobs[minIndex][1]) - jobs[minIndex][0]);
    }

    return answer / jobs.size();
}