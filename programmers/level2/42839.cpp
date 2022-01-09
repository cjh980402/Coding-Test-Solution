#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    int sqrtn = sqrt(n);

    for (int i = 4; i <= sqrtn; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    map<int, int> madeNum;
    int len = numbers.length();

    sort(numbers.begin(), numbers.end()); // next_permutation을 사용하기 전에 필수

    while (1)
    {
        for (int i = 0; i < len; i++)
        {
            madeNum[atoi(numbers.c_str() + i)]++;
        }
        if (!next_permutation(numbers.begin(), numbers.end()))
            break;
    }

    for (auto iter = madeNum.begin(); iter != madeNum.end(); iter++)
    {
        if (isPrime(iter->first))
            answer++;
    }

    return answer;
}