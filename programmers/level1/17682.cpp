#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    vector<int> scores = {0}; // 첫번째에서 스타상인 경우 편한 계산을 위해 0점을 미리 넣어둠
    istringstream is(dartResult);

    while (1)
    {
        int base;
        is >> base;
        if (!is)
            break; // 입력의 끝까지 스캔한 경우 반복을 종료한다.
        char type = is.get();
        // 점수의 영역에 따른 보너스 계산
        if (type == 'D')
            base *= base;
        else if (type == 'T')
            base *= (base * base);
        scores.push_back(base);

        // peek을 통해 버퍼에 일단 남겨두고 다음 문자를 검토한다.
        char next = is.peek();
        if (next == '*' || next == '#')
        {
            is.get(); // 옵션에 해당하는 글자가 맞을 경우 해당 글자를 버린다.
            if (next == '*')
            {
                // 스타상 계산
                scores[scores.size() - 2] *= 2;
                scores[scores.size() - 1] *= 2;
            }
            else if (next == '#')
            {
                // 아차상 계산
                scores[scores.size() - 1] *= -1;
            }
        }
    }

    // 총 점 계산
    for (int i : scores)
        answer += i;

    return answer;
}