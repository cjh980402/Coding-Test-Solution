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
    // 주어진 튜플 정보를 배열로 파싱
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

    // 배열을 크기 순으로 오름차순 정렬
    sort(sets.begin(), sets.end(), [](vector<int> a, vector<int> b)
         { return a.size() < b.size(); });

    // 크기순으로 정렬된 sets를 순회하면서 answer에 들어가지 않은 원소가 확인되면 넣어줌
    for (const vector<int> &a : sets)
    {
        for (int b : a)
        {
            if (find(answer.begin(), answer.end(), b) == answer.end())
                answer.push_back(b);
        }
    }

    return answer;
}