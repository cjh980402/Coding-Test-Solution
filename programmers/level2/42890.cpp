#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation)
{
    int answer = 0;
    int range = 1 << relation[0].size(); // 키를 조합하는 경우의 수
    vector<int> candidates;

    for (int i = 1; i < range; i++)
    {
        set<string> cache;
        for (const vector<string> &r : relation)
        {
            string key;
            for (int j = 0; j < r.size(); j++)
            {
                if (i & (1 << j))
                {
                    key += r[j];
                }
            }
            cache.insert(key);
        }
        if (cache.size() == relation.size())
        {
            // 유일성을 만족했으니 최소성을 검토해야한다.
            // i가 c에 해당하는 비트를 다 갖고 있으면 최소성을 만족하지 못하는 경우
            bool isCandidates = true;
            for (int c : candidates)
            {
                if ((c & i) == c)
                {
                    isCandidates = false;
                    break;
                }
            }
            if (isCandidates)
            {
                candidates.push_back(i);
                answer++;
            }
        }
    }

    return answer;
}