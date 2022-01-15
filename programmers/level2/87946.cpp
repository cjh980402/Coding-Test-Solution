#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = 0;
    // 어느 한개를 기준으로 풀 수 없는 문제이므로 순열을 통한 완전탐색을 수행한다.

    sort(dungeons.begin(), dungeons.end());

    while (1)
    {
        int now = 0, nowK = k;
        for (const vector<int> d : dungeons)
        {
            if (nowK >= d[0])
            {
                nowK -= d[1];
                now++;
            }
        }
        if (now > answer)
            answer = now;
        if (!next_permutation(dungeons.begin(), dungeons.end()))
            break;
    }

    return answer;
}