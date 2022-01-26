#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;

    sort(d.begin(), d.end());
    // 정렬 후 작은 금액부터 예산에서 차감한다 (그리디적 방법)
    for (int i : d)
    {
        budget -= i;
        if (budget >= 0)
            answer++;
        else
            break;
    }

    return answer;
}