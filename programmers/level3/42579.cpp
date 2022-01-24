#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    unordered_map<string, int> count;
    unordered_map<string, int> answer_count;
    int len = genres.size();
    vector<int> answer;
    vector<tuple<string, int, int>> plays_indexed(len);

    for (int i = 0; i < len; i++)
    {
        // 각 노래에 대한 정보 저장
        plays_indexed[i] = tuple(genres[i], plays[i], i);
        count[genres[i]] += plays[i];
    }

    // 재생 횟수와 장르 기준으로 내림차순 정렬
    sort(plays_indexed.begin(), plays_indexed.end(), [&](const tuple<string, int, int> &a, const tuple<string, int, int> &b)
         { return get<0>(a) == get<0>(b) ? get<1>(a) > get<1>(b) : count[get<0>(a)] > count[get<0>(b)]; });

    for (int i = 0; i < len; i++)
    {
        // 2개 미만으로 선택된 장르의 곡을 추가하기
        if (answer_count[get<0>(plays_indexed[i])] < 2)
        {
            answer.push_back(get<2>(plays_indexed[i]));
            answer_count[get<0>(plays_indexed[i])]++;
        }
    }

    return answer;
}