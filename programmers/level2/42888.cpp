#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<vector<string>> split_record;
    map<string, string> nickList;

    for (const string &r : record)
    {
        istringstream ss(r);
        string stringBuffer;
        vector<string> x;
        while (getline(ss, stringBuffer, ' '))
        {
            x.push_back(stringBuffer);
        }
        split_record.push_back(x);
        if (x[0] == "Enter" || x[0] == "Change")
        {
            nickList[x[1]] = x[2];
        }
    }

    for (const vector<string> &sr : split_record)
    {
        if (sr[0] == "Enter")
        {
            answer.push_back(nickList[sr[1]] + "님이 들어왔습니다.");
        }
        if (sr[0] == "Leave")
        {
            answer.push_back(nickList[sr[1]] + "님이 나갔습니다.");
        }
    }

    return answer;
}