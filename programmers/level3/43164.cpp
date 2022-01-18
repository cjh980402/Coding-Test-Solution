#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 같은 내용의 티켓이 있을 수 있으므로 multiset 사용
vector<string> dfs(map<string, multiset<string>> ticket_graph, vector<string> path, const string &prev, const string &now)
{
    // erase(value)를 사용시 해당하는 값을 모두 지우므로 1개만 지우기 위해 이터레이터를 사용
    ticket_graph[prev].erase(ticket_graph[prev].find(now));
    path.push_back(now);
    vector<string> maxPath = path;

    for (const string &s : ticket_graph[now])
    {
        vector<string> temp = dfs(ticket_graph, path, now, s);
        if (maxPath.size() < temp.size())
            maxPath = temp;
    }

    return maxPath;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    map<string, multiset<string>> ticket_graph; // 중복 허용을 위한 multiset 사용

    for (const vector<string> &t : tickets)
    {
        ticket_graph[t[0]].insert(t[1]);
    }
    ticket_graph["HEAD"].insert("ICN");

    answer = dfs(ticket_graph, answer, "HEAD", "ICN");

    return answer;
}