#include <bits/stdc++.h>

using namespace std;

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c)
{
    int answer = 0;
    vector<int> dist(n, 1000000);

    for (int i : c)
    {
        dist[i] = 0; // space station에 해당하는 경우 거리가 0
    }

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == 0)
            continue; // space station인 경우 계산할 필요가 없음

        if (i > 0)
            dist[i] = dist[i - 1] + 1; // 이전 지역 값에 거리 1을 추가한 값으로 초기화

        int maxJ = min(i + dist[i], n - 1); // 오른쪽에 있을 space station을 탐색할 범위
        for (int j = i + 1; j <= maxJ; j++)
        {
            if (dist[j] == 0)
            {
                if (j - i < dist[i])
                    dist[i] = j - i; // 오른쪽이 더 가까운 경우 값 갱신
                break;
            }
        }

        if (dist[i] > answer)
            answer = dist[i]; // answer에는 최대 거리 저장
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, m;
    cin >> n >> m;

    vector<int> c(m);

    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }

    int result = flatlandSpaceStations(n, c);

    fout << result << "\n";

    fout.close();

    return 0;
}