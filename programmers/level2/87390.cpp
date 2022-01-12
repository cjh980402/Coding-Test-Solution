#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer(right - left + 1);

    for (long long a = left; a <= right; a++)
    {
        int i = a / n;
        int j = a % n;
        answer[a - left] = (j < i) ? (i + 1) : (j + 1);
    }

    return answer;
}