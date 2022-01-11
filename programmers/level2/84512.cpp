#include <string>
#include <cmath>

using namespace std;

int charIndex(char c)
{
    if (c == 'A')
        return 0;
    else if (c == 'E')
        return 1;
    else if (c == 'I')
        return 2;
    else if (c == 'O')
        return 3;
    else if (c == 'U')
        return 4;
}

int solution(string word)
{
    int answer = 0;
    int max = 5 + 5 * 5 + 5 * 5 * 5 + 5 * 5 * 5 * 5 + 5 * 5 * 5 * 5 * 5; // 1, 2, 3, 4, 5글자 경우의 수의 합

    for (int i = 0; i < word.length(); i++)
    {
        answer += (1 + charIndex(word[i]) * max / pow(5, i + 1));
        // 최소 1개의 간격이 증가, charIndex는 글자의 번호, max / pow(5, i+1)은 i번째 자리의 글자 하나 사이 간격 -> 각 단계마다 answer에는 각 글자에 해당하는 간격이 더해짐
    }

    return answer;
}