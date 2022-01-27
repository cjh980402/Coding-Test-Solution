#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    unordered_map<string, int> dict;
    int last = 26;

    // 사전의 초기값
    for (int i = 0; i < last; i++)
    {
        dict[string(1, 'A' + i)] = i + 1;
    }

    for (int i = 0; i < msg.length();)
    {
        string now(1, msg[i]);
        int j = i + 1;
        // 사전에 없는 단어가 나올때까지 탐색을 진행
        for (; j < msg.length(); j++)
        {
            if (dict[now + msg[j]])
                now += msg[j];
            else
                break;
        }
        // 기존 단어의 번호 출력
        answer.push_back(dict[now]);
        // 사전에 없는 새 단어를 추가
        dict[now + msg[j]] = ++last;
        i += now.length();
    }

    return answer;
}