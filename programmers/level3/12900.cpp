#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> &cache, int n)
{
    if (cache[n] != -1)
        return cache[n];

    // dfs(n) == dfs(n-1) + dfs(n-2)
    int result = 0;
    if (n > 2)
        result = (result + dfs(cache, n - 2)) % 1000000007;
    if (n > 1)
        result = (result + dfs(cache, n - 1)) % 1000000007;
    return cache[n] = result;
}

int solution(int n)
{
    vector<int> cache(n + 1, -1);
    // 초기값: n이 1일때 가지수는 1, n이 2일때 가지수는 2
    cache[1] = 1;
    cache[2] = 2;
    return dfs(cache, n);
}