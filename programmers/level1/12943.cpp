using namespace std;

int solution(int num)
{
    int answer = 0;
    long long now = num; // int형의 오버플로우 방지를 위해 long long 사용

    // 1이 입력으로 들어온 경우 작업을 수행할 필요가 없음
    while (now != 1)
    {
        if (now % 2)
            now = 3 * now + 1; // 오버플로우 발생 가능
        else
            now /= 2;

        answer++;
        if (answer >= 500)
            break;
    }

    return now == 1 ? answer : -1;
}