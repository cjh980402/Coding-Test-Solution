#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number)
{
    unordered_set<int> len_num_map[9]; // 길이(0~8)에 해당하는 숫자를 모아둔 테이블

    for (int i = 1, n = N; i < 9; i++, n = 10 * n + N)
    {
        // N이 5일때 5, 55, 555 같은 수는 최솟값이 숫자의 길이와 같음
        len_num_map[i].insert(n);

        // i개의 N으로 만들 수 있는 수 = (i-j)개의 N으로 만들 수 있는 수와 j개의 N으로 만들 수 있는 수의 조합 (j는 1이상 i미만)
        for (int j = 1; j < i; j++)
        {
            for (int first : len_num_map[i - j])
            {
                for (int second : len_num_map[j])
                {
                    // 아래의 연산은 자체적으로 (first) op (second)이므로 괄호연산이 고려된다.
                    len_num_map[i].insert(first + second);     // 덧셈
                    len_num_map[i].insert(first - second);     // 뺄셈
                    len_num_map[i].insert(first * second);     // 곱셈
                    if (second != 0)                           // 0으로 나누는 경우 방지
                        len_num_map[i].insert(first / second); // 나눗셈
                }
            }
        }

        if (len_num_map[i].find(number) != len_num_map[i].end())
            return i;
    }

    return -1; // 8번 이내에서 나오지 못한 수가 도달함
}