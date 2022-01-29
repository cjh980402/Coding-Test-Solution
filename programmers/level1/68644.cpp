#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    set<int> answer; // 중복제거+정렬 목적으로 ordered set 사용

    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
            answer.insert(numbers[i] + numbers[j]); // 두 원소의 합을 set에 넣음
    }

    return vector<int>(answer.begin(), answer.end()); // set을 통해 vector 생성
}