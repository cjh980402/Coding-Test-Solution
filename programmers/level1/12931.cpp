using namespace std;

int solution(int n)
{
    int answer = 0;

    for (; n; n /= 10)
    {
        answer += (n % 10); // 자리수를 가져와서 더한다.
    }

    return answer;
}