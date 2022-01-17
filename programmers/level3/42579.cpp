#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    map<string, int> count;
    map<string, int> answer_count;
    int len = genres.size();
    vector<int> answer;
    vector<tuple<string, int, int>> plays_indexed(len);

    for (int i = 0; i < len; i++)
    {
        plays_indexed[i] = tuple(genres[i], plays[i], i);
        count[genres[i]] += plays[i];
    }

    sort(plays_indexed.begin(), plays_indexed.end(), [&](const tuple<string, int, int> &a, const tuple<string, int, int> &b)
         { return get<0>(a) == get<0>(b) ? get<1>(a) > get<1>(b) : count[get<0>(a)] > count[get<0>(b)]; });

    for (int i = 0; i < len; i++)
    {
        if (answer_count[get<0>(plays_indexed[i])] < 2)
        {
            answer.push_back(get<2>(plays_indexed[i]));
            answer_count[get<0>(plays_indexed[i])]++;
        }
    }

    return answer;
}