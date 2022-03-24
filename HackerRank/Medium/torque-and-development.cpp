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
    // 모든 도시에서 도서관에 접근 가능하게 만드는 최소 비용 찾는 문제
    if (c_lib <= c_road)
    {
        // 도서관 건설 비용이 길 건설 비용 이하일 때는 모든 도시에 도서관을 건설하는게 최적임
        return (long long)n * c_lib; // 오버플로우 방지를 위한 형변환이 필요
    }

    // 인접리스트 형태로 그래프를 저장
    vector<vector<int>> graph(n);
    for (const vector<int> &v : cities)
    {
        graph[v[0] - 1].push_back(v[1] - 1);
        graph[v[1] - 1].push_back(v[0] - 1);
    }

    vector<bool> canAccess(n);
    long long answer = 0;
    queue<int> bfsq;

    // 길 건설 비용이 도서관 건설 비용보다 작은 경우는 각 네트워크 당 하나의 도서관만 설치하면 된다.
    for (int i = 0; i < n; i++)
    {
        // 이미 도서관에 접근 가능한 경우는 제외한다.
        if (canAccess[i])
            continue;

        // i번째 도시에 도서관 설치
        bfsq.push(i);
        canAccess[i] = true;
        answer += c_lib;

        // BFS를 사용하여 i번째 도시와 같은 네트워크에 속한 다른 도시를 길로 연결한다.
        while (!bfsq.empty())
        {
            int now = bfsq.front();
            bfsq.pop();

            for (int c : graph[now])
            {
                // 이미 도서관에 접근 가능한 경우는 제외한다.
                if (canAccess[c])
                    continue;

                // c번째 도시에 길 연결
                bfsq.push(c);
                canAccess[c] = true;
                answer += c_road;
            }
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