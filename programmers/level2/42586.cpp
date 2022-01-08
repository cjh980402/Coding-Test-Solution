#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;

    int day = (100 - progresses[0]) / speeds[0] + ((100 - progresses[0]) % speeds[0] ? 1 : 0);
    int count = 1;
    for (int i = 1; i < progresses.size(); i++)
    {
        if (progresses[i] + speeds[i] * day >= 100)
        {
            count++;
        }
        else
        {
            answer.push_back(count);
            day = (100 - progresses[i]) / speeds[i] + ((100 - progresses[i]) % speeds[i] ? 1 : 0);
            count = 1;
        }
    }
    answer.push_back(count);

    return answer;
}