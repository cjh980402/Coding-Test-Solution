#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    unordered_map<int, pair<unordered_map<string, int>, int>> menu;

    for (string &s : orders)
    {
        sort(s.begin(), s.end());
        int range = 1 << s.length();
        // 모든 경우의 수 조합하기
        for (int i = 1; i < range; i++)
        {
            string key;
            for (int j = 0; j < s.length(); j++)
            {
                if (i & (1 << j))
                    key += s[j];
            }
            // first에는 길이에 해당하는 맵, second에는 그 맵의 최대 value 저장
            if (menu[key.length()].second < ++menu[key.length()].first[key])
                menu[key.length()].second = menu[key.length()].first[key];
        }
    }

    for (int c : course)
    {
        for (const auto &[key, count] : menu[c].first)
        {
            if (count >= 2 && count == menu[c].second)
            {
                answer.push_back(key);
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}