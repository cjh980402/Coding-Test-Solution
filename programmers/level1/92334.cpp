#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer(id_list.size());
    map<string, vector<string>> rList;
    map<string, int> rCount;
    set<string> reports(report.begin(), report.end()); // 중복 신고 제거 목적

    for (const string &r : reports)
    {
        string src, tgt;
        istringstream is(r);

        is >> src >> tgt;
        rList[src].push_back(tgt);
        rCount[tgt]++;
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        const vector<string> &rs = rList[id_list[i]];
        for (const string &r : rs)
            if (rCount[r] >= k)
                answer[i]++;
    }

    return answer;
}