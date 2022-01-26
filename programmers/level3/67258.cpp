#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems)
{
    unordered_set<string> gemType(gems.begin(), gems.end()); // 중복없는 보석의 목록
    int resultL = 0, resultR = 0;
    int minLen = 1000000;
    unordered_map<string, int> nowGem;

    // 배열의 크기가 최대 10만이나 되므로 효율적으로 구성해야함
    // 모든 보석을 포함한 처음 나오는 구간을 찾은 후, 왼쪽값과 오른쪽값을 하나씩 늘리면서 검토한다.
    for (int nowL = 0, nowR = 0; nowL <= nowR; nowL++)
    {
        bool findNewRange = false;
        for (int r = nowR; r < gems.size(); r++)
        {
            nowGem[gems[r]]++;
            if (nowGem.size() == gemType.size())
            {
                nowR = r;
                findNewRange = true;
                // 현재 탐색된 구간이 최소길이인 경우 구간 갱신
                if (minLen > nowR - nowL)
                {
                    minLen = nowR - nowL;
                    resultL = nowL;
                    resultR = nowR;
                }
                // nowL에 해당하는 nowR을 찾았으므로 반복문 종료
                break;
            }
        }
        // nowL ~ gems.size()-1까지 검토를 했는데도 새 구간을 찾지 못했으면 nowL을 늘려도 여전히 찾을 수 없기 때문에 바로 종료
        if (!findNewRange)
            break;

        // 현재 탐색된 구간의 시작값 데이터 삭제
        if (nowGem[gems[nowL]] == 1)
            nowGem.erase(gems[nowL]);
        else
            nowGem[gems[nowL]]--;
        // 현재 탐색된 구간의 끝값 데이터 삭제 (다음 탐색 때 다시 추가되기 때문)
        if (nowGem[gems[nowR]] == 1)
            nowGem.erase(gems[nowR]);
        else
            nowGem[gems[nowR]]--;
    }

    return {resultL + 1, resultR + 1};
}