#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id)
{
    // 각 배열의 크기가 최대 8이므로 최대 8!에 해당하는 모든 경우를 검토해도 오래걸리지 않음
    vector<vector<string>> matchable; // banned_id의 길이와 같은 순열을 모두 모음
    set<set<string>> ban_result;      // 구해진 순열 중 매칭이 되는 순열만 모으기

    int userLen = user_id.size(), banLen = banned_id.size();
    // banLen 길이의 순열을 구해야함 nPr(userLen, banLen)
    vector<int> choice(userLen);
    for (int i = 0; i < banLen; i++)
        choice[i] = 1; // 추후 choice에서 값이 1인 곳과 같은 인덱스의 원소만 추출해서 banLen개의 조합을 구함
    // 이러한 방법으로 조합을 구하는게 가능한 이유는 2종류의 값으로 이루어진 수열의 순열은 n종류의 값으로 이루어진 수열의 조합과 본질적으로 같기 때문이다.
    // choice는 내림차순 정렬된 상태이므로 prev_permutation 사용

    sort(user_id.begin(), user_id.end()); // 오름차순 정렬

    while (1)
    {
        // nowPermu에 먼저 banLen길이의 조합을 담은 후 순열을 구한다.
        vector<string> nowPermu;
        for (int i = 0; i < userLen; i++)
        {
            if (choice[i])
                nowPermu.push_back(user_id[i]);
        }
        // user_id가 정렬된 상태이므로 nowPermu의 초기값도 정렬된 상태
        while (1)
        {
            matchable.push_back(nowPermu);
            if (!next_permutation(nowPermu.begin(), nowPermu.end()))
                break;
        }

        if (!prev_permutation(choice.begin(), choice.end()))
            break;
    }
    // matchable에는 banLen길이의 모든 순열이 들어있음

    // 모든 순열 중에서 banned_id와 내용이 일치하는 순열 찾기
    for (const vector<string> &match : matchable)
    {
        bool isMatch = true;
        for (int i = 0; isMatch && i < banLen; i++)
        {
            // ID 일치여부 체크
            isMatch = match[i].length() == banned_id[i].length();
            for (int j = 0; isMatch && j < match[i].length(); j++)
            {
                if (banned_id[i][j] != '*' && banned_id[i][j] != match[i][j])
                    isMatch = false;
            }
        }
        if (isMatch)
            ban_result.insert(set<string>(match.begin(), match.end())); // set을 사용해서 일치하는 순열을 정렬하였고 ban_result도 set이므로 중복된 내용은 들어가지 않는다.
    }

    return ban_result.size();
}