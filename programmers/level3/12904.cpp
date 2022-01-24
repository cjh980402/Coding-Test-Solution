#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 1; // 팰린드롬의 길이는 최소 1이다. (1글자인 경우)
    unordered_map<char, vector<int>> cmap;

    for (int i = 0; i < s.length(); i++)
        cmap[s[i]].push_back(i); // 각 글자의 위치 저장

    for (const auto &[c, vec] : cmap)
    {
        // 각 글자에 대한 팰린드롬 판별 수행
        for (int ii = 0; ii < vec.size() - 1; ii++)
        {
            for (int jj = ii + 1; jj < vec.size(); jj++)
            {
                // 각 글자에 대해 가능한 조합: i~j 구간의 문자열
                int i = vec[ii], j = vec[jj];
                if (j - i + 1 < answer)
                    continue; // 지금까지 구한 최댓값보다 짧은 길이의 분기는 검사하지 않는다.
                int a = i, b = j;
                for (; a <= b && s[a] == s[b]; a++, b--)
                    ;
                if (a > b)
                    answer = max(answer, j - i + 1); // 팰린드롬으로 판별된 경우 새 값과 기존 값 중 큰 값을 선택한다.
            }
        }
    }

    return answer;
}