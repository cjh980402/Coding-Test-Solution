#include <vector>

using namespace std;

int solution(vector<int> sticker)
{
    int n = sticker.size();
    vector<int> dp1(sticker), dp2(sticker);
    // 두 경우를 모두 계산하는 이유는 첫번째와 두번째 스티커는 동시에 사용할 수 없기 때문
    // dp1은 첫번째 스티커 사용가능: 2~n-2 범위의 스티커 사용 가능
    // dp2는 두번째 스티커 사용가능: 3~n-1 범위의 스티커 사용 가능

    // dp[i-2]+dp[i]: i번째의 스티커를 사용하는 경우
    // dp[i-1]: i번째의 스티커를 사용하지 않는 경우
    dp1[1] = max(dp1[0], dp1[1]);
    for (int i = 2; i <= n - 2; i++)
    {
        dp1[i] = max(dp1[i - 2] + dp1[i], dp1[i - 1]);
    }
    dp2[2] = max(dp2[1], dp2[2]);
    for (int i = 3; i <= n - 1; i++)
    {
        dp2[i] = max(dp2[i - 2] + dp2[i], dp2[i - 1]);
    }

    return max(dp1[n - 2], dp2[n - 1]);
}