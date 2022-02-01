#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int minV = *min_element(arr.begin(), arr.end());

    for (int i : arr)
    {
        if (i != minV)
            answer.push_back(i);
    }

    return answer.empty() ? vector<int>{-1} : answer;
}