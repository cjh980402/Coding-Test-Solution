using namespace std;

bool solution(int x)
{
    int sum = 0;

    for (int n = x; n; n /= 10)
        sum += (n % 10); // 각 자릿수의 합

    return !(x % sum); // 나누어떨어지는 경우 true가 됨
}