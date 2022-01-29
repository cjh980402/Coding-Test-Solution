#include <vector>

using namespace std;

vector<int> solution(int n, long long k)
{
    vector<long long> fac(n, 1); // 팩토리얼은 값이 크므로 long long 사용
    vector<int> nums(n, 1);
    vector<int> answer(n);

    for (int i = 1; i < n; i++)
    {
        fac[i] = i * fac[i - 1]; // 각 자리에서의 수열 개수를 계산할때 사용하기 위한 팩토리얼 값을 미리 계산해둔다.
        nums[i] = i + 1;         // 사용 가능한 숫자 목록
    }
    k--; // 순서를 0번째부터 시작하는 방법으로 계산할 것이므로 k의 값을 1 감소시킨다.

    for (int i = 0; i < n; i++)
    {
        int nowIndex = k / fac[n - i - 1];   // fac[n-i-1]은 다음자리부터의 수열 총 개수이다.
        answer[i] = nums[nowIndex];          // i번째 자리에 해당하는 수 대입
        nums.erase(nums.begin() + nowIndex); // 같은 수는 사용할 수 없으므로 삭제한다.
        k %= fac[n - i - 1];                 // 현재 자리는 계산되었으므로 나머지를 통해 남은 자리들을 계산해야한다.
    }

    return answer;
}