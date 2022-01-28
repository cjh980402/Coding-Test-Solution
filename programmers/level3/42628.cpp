#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations)
{
    deque<int> dq;

    for (const string &s : operations)
    {
        if (s == "D 1" && !dq.empty())
        {
            // 오름차순 정렬 상태이므로 맨 끝이 최댓값
            dq.pop_back();
        }
        else if (s == "D -1" && !dq.empty())
        {
            // 오름차순 정렬 상태이므로 맨 처음이 최솟값
            dq.pop_front();
        }
        else if (s[0] == 'I')
        {
            string temp;
            int data;
            istringstream is(s);
            is >> temp >> data;
            dq.push_back(data);
            // 오름차순 정렬
            sort(dq.begin(), dq.end());
        }
    }

    return dq.empty() ? vector<int>{0, 0} : vector<int>{dq.back(), dq.front()};
}