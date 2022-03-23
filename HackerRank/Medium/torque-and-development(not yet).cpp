#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */
long long roadsAndLibraries(int n, int c_lib, int c_road, const vector<vector<int>> &cities)
{
    // 모든 도시에서 도서관에 접근 가능하게 만드는 최소 비용 찾기
    if (c_lib < c_road)
    {
        // 도서관 건설 비용이 길 건설 비용보다 적으면 모든 도시에 도서관을 건설하는게 최적임
        return n * c_lib;
    }

    vector<pair<int, vector<int>>> graph(n);
    for (const vector<int> &v : cities)
    {
        graph[v[0] - 1].first = v[0] - 1;
        graph[v[0] - 1].second.push_back(v[1] - 1);

        graph[v[1] - 1].first = v[1] - 1;
        graph[v[1] - 1].second.push_back(v[0] - 1);
    }

    sort(graph.begin(), graph.end(), [](const pair<int, vector<int>> &a, const pair<int, vector<int>> &b)
         { return a.second.size() > b.second.size(); });

    vector<bool> canAccess(n);
    long long answer = 0;

    for (int i = 0; i < n; i++)
    {
        const pair<int, vector<int>> &g = graph[i];
        if (canAccess[g.first])
            continue;

        canAccess[g.first] = true;
        answer += c_lib;
        for (int c : g.second)
        {
            if (!canAccess[c])
            {
                canAccess[c] = true;
                answer += c_road;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!canAccess[i])
        {
            canAccess[i] = true;
            answer += c_lib;
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        int n, m, c_lib, c_road;
        cin >> n >> m >> c_lib >> c_road;

        vector<vector<int>> cities(m, vector<int>(2));

        for (int i = 0; i < m; i++)
        {
            cin >> cities[i][0] >> cities[i][1];
        }

        long long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}