#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    unordered_map<string, int> clmap;

    for (const vector<string> &v : clothes)
    {
        clmap[v[1]]++;
    }

    for (const auto &[key, value] : clmap)
    {
        answer *= value + 1;
    }

    return answer - 1;
}