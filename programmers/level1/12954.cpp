#include <vector>

using namespace std;

vector<long long> solution(int x, int n)
{
    vector<long long> answer(n);

    for (int i = 0, now = x; i < n; i++, now += x)
        answer[i] = now;

    return answer;
}