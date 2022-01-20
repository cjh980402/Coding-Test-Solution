#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 보다 최적화된 코드로 업데이트 완료
vector<string> dfs(vector<bool> &used, const vector<vector<string>> &tickets, const string &now, vector<string> answer)
{
    vector<string> maxAns = answer;

    for (int i = 0; i < tickets.size(); i++)
    {
        if (used[i] || tickets[i][0] != now)
            continue;

        // 티켓 사용 표시
        used[i] = true;
        // 경로에 추가
        answer.push_back(tickets[i][1]);
        vector<string> temp = dfs(used, tickets, tickets[i][1], answer);
        // 길이가 긴 경로는 모든 티켓을 사용한 경우이므로 값을 갱신
        if (maxAns.size() < temp.size())
            maxAns = temp;
        // 티켓 사용 제거
        used[i] = false;
        // 경로에서 제거
        answer.pop_back();
    }

    return maxAns;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<bool> used(tickets.size(), false);

    // 알파벳 순서 조건을 만족하기 위해 티켓배열을 오름차순으로 정렬
    sort(tickets.begin(), tickets.end());

    return dfs(used, tickets, "ICN", {"ICN"});
}