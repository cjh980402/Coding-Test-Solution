#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    string nowNum;

    vector<vector<int>> sets;
    int setIndex = -1;
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i] == '{')
        {
            setIndex++;
            sets.push_back(vector<int>());
        }
        if ('0' <= s[i] && s[i] <= '9')
            nowNum += s[i];
        else if (nowNum.length())
        {
            sets[setIndex].push_back(stoi(nowNum));
            nowNum.clear();
        }
    }

    sort(sets.begin(), sets.end(), [](vector<int> a, vector<int> b)
         { return a.size() < b.size(); });

    for (const vector<int> &a : sets)
    {
        for (const int b : a)
        {
            if (find(answer.begin(), answer.end(), b) == answer.end())
                answer.push_back(b);
        }
    }

    return answer;
}