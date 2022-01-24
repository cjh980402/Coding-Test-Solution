#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer(query.size());
    unordered_map<string, vector<int>> all_kind_info;

    for (int i = 0; i < info.size(); i++)
    {
        string data[4]; // lan, job, type, food
        int score;
        istringstream is(info[i]);

        is >> data[0] >> data[1] >> data[2] >> data[3] >> score;
        // 아래 부분은 항상 고정적인 개수만큼 수행됨
        // 모든 key 조합에 대해 미리 점수를 저장해둠
        for (int i = 0; i < 16; i++)
        {
            string key;
            for (int j = 0; j < 4; j++)
            {
                int now = i & (1 << j);
                key += (now ? data[j] : "-");
            }
            all_kind_info[key].push_back(score);
        }
    }

    // 모든 조합의 점수 배열을 오름차순 정렬
    for (auto &[key, scores] : all_kind_info)
        sort(scores.begin(), scores.end());

    for (int i = 0; i < query.size(); i++)
    {
        string lan, job, type, food, temp;
        int score;
        istringstream is(query[i]);

        is >> lan >> temp >> job >> temp >> type >> temp >> food >> score;
        string key = lan + job + type + food;
        // key와 점수를 모두 만족하는 경우 찾기 = all_kind_info[key]에서 score이상의 점수를 가진 경우의 개수를 구해야함
        auto iter = lower_bound(all_kind_info[key].begin(), all_kind_info[key].end(), score);

        answer[i] += (all_kind_info[key].end() - iter);
    }

    return answer;
}