#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times)
{
    // 완전탐색으로 모든 경우를 따지면 시간초과가 된다.
    // 그러므로 이진탐색을 이용하여 범위를 줄이면서 탐색된 시간에서의 심사 완료수가 n이 되는 경우를 찾아본다. 이때의 시간은 최솟값이어야함
    long long left = 1, right = 1e18, mid; // 1*1(1명, 1분), 10억*10억(10억명, 10억분)
    // 이진탐색 코드, sum == n을 만족하는 최솟값 탐색될때까지 반복된다
    while (left < right)
    {
        mid = (left + right) / 2;
        // mid의 값이 매우 크기 때문에 sum도 long long으로 선언
        long long sum = 0;
        // i번째 심사관은 mid초 동안 최대 mid/times[i]명 심사 가능
        for (int t : times)
            sum += mid / t;
        if (n <= sum)
        {
            right = mid; // 값이 같은 경우에도 좌측으로 추가적으로 탐색을 진행하므로 최종적으로 sum == n을 만족하는 최솟값 탐색 가능
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}