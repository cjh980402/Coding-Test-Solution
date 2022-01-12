#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos)
{
    string answer, mod;
    int max = 0;

    // 문제를 간소화 하기 위해 X#을 x로 변경(m과 musicinfos에 해당)
    for (char c : m)
    {
        if (c == '#')
            mod.back() = tolower(mod.back());
        else
            mod += c;
    }

    for (const string &s : musicinfos)
    {
        int sharpCount = 0;
        vector<string> v;
        string now(1, s[0]);
        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] == ',')
            {
                v.push_back(now);
                now.clear();
            }
            else if (s[j] == '#')
                sharpCount++, now.back() = tolower(now.back());
            else
                now += s[j];
        }
        v.push_back(now);

        int time = (stoi(v[1].substr(0, 2)) - stoi(v[0].substr(0, 2))) * 60 + (stoi(v[1].substr(3, 2)) - stoi(v[0].substr(3, 2))); // 노래의 재생 시간 계산

        string vv(v[3]);
        while (vv.length() < time)
            vv += v[3];
        vv = vv.substr(0, time); // 최종적으로 vv에는 재생된 노래의 문자열이 들어감

        if (vv.find(mod) != string::npos && max < time)
        {
            // 들은 내용이 존재하면서, 재생시간이 더 긴 경우에 값 갱신
            answer = v[2];
            max = time;
        }
    }

    return answer.length() == 0 ? "(None)" : answer; // 해당하는게 없는 경우는 (None) 반환
}