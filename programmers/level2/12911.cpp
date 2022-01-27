#include <string>
#include <vector>

using namespace std;

int countOne(int n)
{
    int count = 0;

    for (; n; n /= 2)
    {
        if (n % 2)
            count++;
    }

    return count;
}

int solution(int n)
{
    int answer = n + 1, count = countOne(n);

    for (; true; answer++)
    {
        if (count == countOne(answer))
            return answer;
    }
}