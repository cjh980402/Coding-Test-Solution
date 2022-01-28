#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int countDiff(const string &a, const string &b)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            count++;
    }
    return count;
}

int solution(string begin, string target, vector<string> words)
{
    unordered_map<string, vector<string>> diffmap;
    queue<pair<string, int>> bfsq;
    int len = words.size();
    unordered_map<string, int> dist;

    // 시작 단어와 1글자만 다른 단어들 탐색
    for (const string &w : words)
    {
        if (countDiff(begin, w) == 1)
            diffmap[begin].push_back(w);
    }

    // words내의 조합에서 1글자만 다른 단어들 탐색
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (countDiff(words[i], words[j]) == 1)
            {
                diffmap[words[i]].push_back(words[j]);
                diffmap[words[j]].push_back(words[i]);
            }
        }
    }

    // BFS를 이용한다
    dist[begin] = 0;
    bfsq.push(pair(begin, dist[begin]));

    while (!bfsq.empty())
    {
        auto [now, cost] = bfsq.front();
        bfsq.pop();

        for (const string &s : diffmap[now])
        {
            if (!dist[s])
            {
                dist[s] = cost + 1;
                // BFS 과정 중간에서 target이 발견된 경우 최소 비용이므로 바로 반환한다.
                if (s == target)
                    return dist[s];
                bfsq.push(pair(s, dist[s]));
            }
        }
    }
    // BFS 과정에서 target이 발견되지 못한 경우는 words안에 target이 없는 경우이다.
    return 0;
}