#include <vector>

using namespace std;

int solution(vector<int> stones, int k)
{
    int answer = 0, min = 2147483647, max = 0;

    // stones에서 최댓값, 최솟값을 찾는다. 돌의 값이 0이되면 못 건너므로 건널 수 있는 사람은 두 수의 범위 내기 때문이다.
    for (int s : stones)
    {
        if (s > max)
            max = s;
        if (s < min)
            min = s;
    }

    // 이진탐색을 통해 min~max 범위 내에서 적절한 값을 찾는다.
    while (min <= max)
    {
        int mid = (min + max) / 2;

        // mid 명이 징검다리를 건널 수 있는지 확인한다. mid명이 이미 건넜다고 가정할 시 횟수를 다 소진한 돌이 연속으로 있는 최대 개수를 찾아서 판별한다.
        int maxCount = 0, count = 0;
        for (int s : stones)
        {
            if (s - mid > 0)
                count = 0;
            else
                count++;
            if (maxCount < count)
                maxCount = count;
        }

        if (maxCount < k)
        {
            // maxCount가 k보다 작음: mid 명이 충분히 건너는 경우
            min = mid + 1;
        }
        else if (maxCount >= k)
        {
            // maxCount가 k 초과임: mid 명이 건너지 못하는 경우
            // maxCount가 k랑 같음: 일단 mid 명이 건널 수 있다고 생각할 수도 있지만, 더 적은 인원이었을 때 maxCount가 k랑 이미 같은 경우가 발생했을 수도 있으므로 좌측으로 재탐색을 해본다.
            max = mid - 1;
        }
    }

    return min;
}