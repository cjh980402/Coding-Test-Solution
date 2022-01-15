#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    int answer = 0;
    char people[] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    // 순열을 이용하여 모든 순서에 대해 조건을 만족하는지 검사하기
    while (1)
    {
        int correct = 0;
        for (const string &d : data)
        {
            char left = d[0], right = d[2], oper = d[3];
            int dist = d[4] - '0';
            int leftIndex = 0;
            for (int i = 1; i < 8; i++)
            {
                if (people[i] == left)
                    leftIndex = i;
            }
            int rightIndex = 0;
            for (int i = 1; i < 8; i++)
            {
                if (people[i] == right)
                    rightIndex = i;
            }
            int realDist = abs(rightIndex - leftIndex) - 1; // 현재 순서에서의 간격
            if ((oper == '<' && realDist < dist) || (oper == '>' && realDist > dist) || (oper == '=' && realDist == dist))
                correct++;
            else
                break;
        }
        if (correct == data.size())
            answer++;
        if (!next_permutation(people, people + 8))
            break;
    }

    return answer;
}