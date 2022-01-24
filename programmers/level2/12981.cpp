#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer(2);
    unordered_set<string> list;

    list.insert(words[0]);
    for (int i = 1; i < words.size(); i++)
    {
        if (list.find(words[i]) != list.end() || words[i - 1].back() != words[i].front())
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        list.insert(words[i]);
    }

    return answer;
}