#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        array<vector<int>, 2> data = {vector<int>(n), vector<int>(n)};

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> data[i][j];
            }
        }

        // 상, 하, 좌, 우로 붙어있는 스티커는 사용 불가 -> 대각선으로만 추가 사용 가능
        // 가로 거리가 3이상인 대각선부터는 그 미만 거리의 대각선을 사용하여 지날 수 있는 지점이다.
        // 가로 거리 1, 2인 대각선만 사용하여 점수를 계산하면 된다.
        array<vector<int>, 2> score(data); // 각 지점에서 가능한 최소 점수는 해당 스티커를 1개만 사용한 경우이므로 data의 복사본으로 생성한다.
        for (int i = 0; i + 1 < n; i++)
        {
            // 가로 거리 1인 대각선
            score[0][i + 1] = max(score[0][i + 1], score[1][i] + data[0][i + 1]);
            score[1][i + 1] = max(score[1][i + 1], score[0][i] + data[1][i + 1]);
            // 가로 거리 2인 대각선
            if (i + 2 < n)
            {
                score[0][i + 2] = max(score[0][i + 2], score[1][i] + data[0][i + 2]);
                score[1][i + 2] = max(score[1][i + 2], score[0][i] + data[1][i + 2]);
            }
        }

        cout << max(score[0][n - 1], score[1][n - 1]) << endl;
    }

    return 0;
}