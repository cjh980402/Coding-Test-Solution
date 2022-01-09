#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations)
{
    int len = citations.size();

    sort(citations.rbegin(), citations.rend());
    for (int i = 0; i < len - 1; i++)
    {
        if (i + 1 <= citations[i] && i + 1 >= citations[i + 1])
            return i + 1;
    }

    return citations[len - 1] >= len ? len : 0;
}