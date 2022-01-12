#include <vector>

using namespace std;

void dfs(const vector<vector<int>> &arr, vector<int> &answer, int r, int c, int len)
{
    int first = arr[r][c];
    for (int i = r; i < r + len; i++)
    {
        for (int j = c; j < c + len; j++)
        {
            if (arr[i][j] != first)
            {
                dfs(arr, answer, r, c, len / 2);
                dfs(arr, answer, r + len / 2, c, len / 2);
                dfs(arr, answer, r, c + len / 2, len / 2);
                dfs(arr, answer, r + len / 2, c + len / 2, len / 2);
                return;
            }
        }
    }
    answer[first]++;
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer(2);

    dfs(arr, answer, 0, 0, arr.size());

    return answer;
}