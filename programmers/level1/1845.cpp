#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0, halfN = nums.size() / 2, min = 200000, max = 1;
    int count[200000] = {0};

    for (int n : nums)
    {
        count[n - 1]++; // 개수 세기
        if (n > max)
            max = n;
        if (n < min)
            min = n;
    }

    sort(count + min - 1, count + max);

    // 폰켓몬의 종류 개수만 알면 되므로 세부 항목 내용은 불필요함
    for (int i = min - 1; i < max; i++)
    {
        if (count[i] > 0)
        {
            halfN--;
            answer++;
        }
        if (halfN <= 0)
            break;
    }

    return answer;
}