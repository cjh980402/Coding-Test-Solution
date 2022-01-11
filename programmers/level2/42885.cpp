#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0, pass = 0;

    sort(people.begin(), people.end());

    for (int i = 0, j = people.size() - 1; pass < people.size();)
    {
        if (people[i] + people[j] > limit)
        {
            pass++;
        }
        else
        {
            i++;
            pass += 2;
        }
        answer++;
        j--;
    }

    return answer;
}