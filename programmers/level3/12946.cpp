#include <vector>

using namespace std;

void recursive(vector<vector<int>> &answer, int n, int src, int tgt)
{
    if (n > 1)
    {
        int mid = src ^ tgt;
        recursive(answer, n - 1, src, mid); // 제일 아래를 제외한 n-1개를 src에서 mid로 이동
        recursive(answer, 1, src, tgt);     // 제일 아래 1개를 src에서 tgt로 이동
        recursive(answer, n - 1, mid, tgt); // 처음에 이동시킨 mid에 있던 n-1개를 tgt로 이동
    }
    else
    {
        answer.push_back({src, tgt}); // 1개만 있을때는 바로 tgt로 이동
    }
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;

    recursive(answer, n, 1, 3);

    return answer;
}