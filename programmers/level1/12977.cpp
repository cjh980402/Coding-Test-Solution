#include <vector>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n < 4)
        return true;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int solution(vector<int> nums)
{
    int answer = 0, len = nums.size();

    for (int i = 0; i < len - 2; i++)
    {
        for (int j = i + 1; j < len - 1; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                if (isPrime(nums[i] + nums[j] + nums[k]))
                    answer++;
            }
        }
    }

    return answer;
}