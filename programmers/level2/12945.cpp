#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0, before2 = 0, before1 = 1;

    for (int i = 2; i <= n; i++)
    {
        answer = (before2 + before1) % 1234567;
        before2 = before1;
        before1 = answer;
    }

    return answer;
}