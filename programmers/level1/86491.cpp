#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int maxW = 0, maxH = 0;

    for (const vector<int> &s : sizes)
    {
        int w, h;
        // 길이가 더 긴 방향을 가로로 설정
        if (s[0] > s[1])
            w = s[0], h = s[1];
        else
            w = s[1], h = s[0];
        // 최댓값 갱신
        if (w > maxW)
            maxW = w;
        if (h > maxH)
            maxH = h;
    }

    return maxW * maxH;
}