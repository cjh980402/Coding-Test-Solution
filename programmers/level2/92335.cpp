#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(long long n)
{
    // 큰 값이 들어올 수 있으므로 n의 자료형은 long long이다.
    if (n < 2)
        return false;

    int sqrtn = sqrt(n);

    for (int i = 2; i <= sqrtn; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

string decToK(int n, int k)
{
    string knum;
    for (; n; n /= k)
    {
        knum = (char)(n % k + '0') + knum;
    }
    return knum;
}

int solution(int n, int k)
{
    int answer = 0;
    string temp, knum = decToK(n, k);

    for (int i = 0; i < knum.length(); i++)
    {
        if (knum[i] != '0')
            temp += knum[i];
        if (temp.length() > 0 && (i == knum.length() - 1 || knum[i] == '0'))
        {
            // 주의사항: stoi를 사용하면 범위 초과때문에 에러가 나므로 stoll을 사용한다
            if (isPrime(stoll(temp)))
                answer++;
            temp.clear();
        }
    }

    return answer;
}