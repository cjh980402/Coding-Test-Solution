#include <string>
#include <vector>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int solution(string name)
{
    int answer = 0;
    vector<int> notA;

    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] != 'A' && i > 0)
        {
            notA.push_back(i);
        }
        answer += min(name[i] - 'A', 'A' - (name[i] - 26));
    }
    if (notA.size() > 0)
    {
        int firstNotA = notA[0], lastNotA = notA.back();
        // 순차이동
        int c1 = lastNotA - firstNotA + min(firstNotA, name.length() - lastNotA);
        // 되돌아가기
        int c2 = 2147483647;
        for (int i = 0; i < notA.size() - 1; i++)
        {
            int rightleft = 2 * notA[i] + name.length() - notA[i + 1];
            int leftright = 2 * (name.length() - notA[i + 1]) + notA[i];
            c2 = min(min(rightleft, leftright), c2);
        }

        answer += min(c1, c2);
    }

    return answer;
}