#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    int zeroCount = 0, winCount = 0;

    for (int lt : lottos)
    {
        if (lt == 0)
        {
            zeroCount++;
        }
        else if (find(win_nums.begin(), win_nums.end(), lt) != win_nums.end())
        {
            winCount++;
        }
    }

    answer.push_back(min(6, 7 - (zeroCount + winCount)));
    answer.push_back(min(6, 7 - (winCount)));

    return answer;
}