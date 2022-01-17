#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int left = j > 0 ? triangle[i - 1][j - 1] : -1;
            int right = j < triangle[i - 1].size() ? triangle[i - 1][j] : -1;
            triangle[i][j] += max(left, right);
        }
    }

    return *max_element(triangle.back().begin(), triangle.back().end());
}