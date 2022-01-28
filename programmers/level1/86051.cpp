#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
    int sum = 0;
    for (int n : numbers)
        sum += n;
    return 45 - sum;
}