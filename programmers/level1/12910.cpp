#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;

    for (int n : arr)
    {
        if (n % divisor == 0)
        {
            // divisor로 나누어 떨어지는 경우
            answer.push_back(n);
        }
    }

    sort(answer.begin(), answer.end()); // 오름차순 정렬

    return answer.empty() ? vector<int>{-1} : answer;
}