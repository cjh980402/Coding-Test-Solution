#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    for (const string &s : skill_trees)
    {
        unordered_map<char, int> now_tree;

        for (int i = 0; i < s.length(); i++)
        {
            now_tree[s[i]] = i + 1; // 스킬트리에서의 인덱스 저장
        }

        int count = 0;
        for (int i = 1; i < skill.length(); i++)
        {
            if (!now_tree[skill[i - 1]] && now_tree[skill[i]])
                break; // 선행스킬이 스킬트리에 없는 경우
            else if (now_tree[skill[i - 1]] && now_tree[skill[i]])
            {
                // 선행스킬과 후속스킬이 모두 스킬트리에 있는 경우
                if (now_tree[skill[i - 1]] < now_tree[skill[i]])
                    // 선행스킬이 먼저 스킬트리에 나온 경우
                    count++;
            }
            else // 후속스킬이 스킬트리에 없거나 선행스킬 후속스킬 모두 없는 경우
                count++;
        }
        if (count == skill.length() - 1)
            answer++;
    }

    return answer;
}