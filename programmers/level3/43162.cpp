#include <vector>

using namespace std;

void dfs(const vector<vector<int>> &computers, vector<bool> &visit, int now, int prev)
{
    for (int i = 0; i < computers[now].size(); i++)
    {
        if (i != prev && !visit[i] && computers[now][i])
            visit[i] = true, dfs(computers, visit, i, now);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visit(computers.size());

    for (int i = 0; i < computers.size(); i++)
    {
        if (!visit[i])
        {
            visit[i] = true, dfs(computers, visit, i, -1);
            answer++;
        }
    }

    return answer;
}