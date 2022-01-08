#include <string>
#include <vector>

using namespace std;

int search(vector<int> numbers, int target, int i, int sum)
{
    if (i == numbers.size())
        return sum == target ? 1 : 0;
    return search(numbers, target, i + 1, sum - numbers[i]) + search(numbers, target, i + 1, sum + numbers[i]);
}

int solution(vector<int> numbers, int target)
{
    int answer = search(numbers, target, 0, 0);
    return answer;
}