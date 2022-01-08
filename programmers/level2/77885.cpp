#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] % 2)
        {
            // 홀수인 경우 추가적인 계산 필요
            for (int j = 1; j < 50; j++)
            {
                if (!(numbers[i] & (1LLU << j)))
                {
                    // 제일 처음 만나는 0을 1로 바꾸기
                    numbers[i] |= (1LLU << j);
                    // 그 전 위치에 있는 1을 0으로 바꾸기
                    numbers[i] &= ~(1LLU << (j - 1));
                    break;
                }
            }
        }
        else
            numbers[i]++; // 짝수인 경우 1만 더하면 원하는 값
    }

    return numbers;
}