#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<pair<double, int>> rates(N);

    sort(stages.begin(), stages.end());

    for (int now = 1, start = 0; now <= N; now++)
    {
        auto overNow = upper_bound(stages.begin() + start, stages.end(), now); // 현재 스테이지를 통과한 첫 사람
        double nowFail = overNow - (stages.begin() + start);                   // 현재 스테이지를 실패한 사람 수
        // now 스테이지에 도달한 사람이 없는 경우 nowFail은 0, 이 때의 실패율은 0으로 정의해야함
        rates[now - 1] = pair(nowFail == 0 ? nowFail : nowFail / (stages.size() - start), now);
        start = overNow - stages.begin();
    }

    sort(rates.begin(), rates.end(), [](const pair<double, int> &a, const pair<double, int> &b)
         { return a.first == b.first ? a.second < b.second : a.first > b.first; });

    for (const auto &[rate, stage] : rates)
        answer.push_back(stage);

    return answer;
}