#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, invalidStart = 1;

    for (int station : stations)
    {
        int len = max(0, station - w - invalidStart);                // 통신이 불가능한 구간의 길이
        answer += (len / (2 * w + 1) + (len % (2 * w + 1) ? 1 : 0)); // 길이를 2*w+1로 나눈 값을 소수점 아래에서 올린 개수만큼 기지국이 필요하다.
        invalidStart = station + w + 1;                              // 현재 기지국의 범위를 벗어난 지역의 시작지점
    }

    if (invalidStart <= n)
        answer += ((n + 1 - invalidStart) / (2 * w + 1) + ((n + 1 - invalidStart) % (2 * w + 1) ? 1 : 0)); // 마지막 기지국 이후에 통신 불가능한 구간이 있는 경우 추가로 계산한다.

    return answer;
}