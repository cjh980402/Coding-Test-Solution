#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int before = -1; // arr에 없는 값으로 초기화

    for (int n : arr)
    {
        if (n != before)
        {
            // 이전의 수와 다르면 n을 추가한다.
            answer.push_back(n);
        }
        before = n;
    }

    return answer;
}