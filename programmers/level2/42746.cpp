#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> strs(numbers.size());

    for (int i = 0; i < numbers.size(); i++)
        strs[i] = to_string(numbers[i]);

    sort(strs.begin(), strs.end(), [](const string &a, const string &b)
         { return (a + b) > (b + a); });

    for (const string &s : strs)
        answer += s;

    return answer[0] == '0' ? "0" : answer;
}