#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> routes)
{
    int answer = 0;

    sort(routes.begin(), routes.end()); // 경로를 오름차순 정렬

    int start = routes[0][0], end = routes[0][1];
    for (const vector<int> &r : routes)
    {
        int tempStart = max(start, r[0]), tempEnd = min(end, r[1]);

        if (tempStart > tempEnd)
        {
            // 현재 경로까지 추가한 임시 구간에는 카메라 설치가 불가능한 경우 이전 구간에 카메라를 설치
            answer++;
            start = r[0];
            end = r[1];
        }
        else
        {
            // 카메라 설치가 가능한 경우는 구간을 갱신한다.
            start = tempStart;
            end = tempEnd;
        }
    }

    return ++answer; // 마지막 구간은 for문 내부에서 추가가 안되므로 반환하기 전에 더해준다.
}