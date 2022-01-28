using namespace std;

int countDiv(int n)
{
    // 약수 개수 구하는 함수
    int count = 0;

    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            count++;

    return count;
}

int solution(int left, int right)
{
    int answer = 0;

    for (int i = left; i <= right; i++)
    {
        answer += (countDiv(i) % 2 ? -i : i); // 문제의 조건
    }

    return answer;
}