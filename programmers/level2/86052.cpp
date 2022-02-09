#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<int> answer;
    vector<vector<vector<bool>>> visit(m, vector<vector<bool>>(n, vector<bool>(4))); // grid의 각 지점과 4방향에 대응하여 방문여부를 확인할 배열
    // 다음과 같이 숫자와 방향을 대응 - 0: 위, 1: 우, 2: 하, 3: 좌

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int d = 0; d < 4; d++)
            {
                if (visit[i][j][d])
                    continue; // 이미 방문된 지점+방향은 이전에 계산된 사이클이므로 계산을 수행하지 않는다.

                // i, j, d는 시작지점의 좌표와 발사 방향
                int nowR = i, nowC = j, nowD = d, nowLen = 0;

                while (1)
                {
                    visit[nowR][nowC][nowD] = true; // (nowR, nowC)에서 nowD 방향으로 빛을 발사함

                    // 회전과 좌표이동 모두 나머지 연산을 이용하여 순환을 간단하게 적용함
                    // 각 방향에 맞게 좌표 이동
                    if (nowD == 0)
                    {
                        nowR = (nowR - 1 + m) % m;
                    }
                    else if (nowD == 1)
                    {
                        nowC = (nowC + 1) % n;
                    }
                    else if (nowD == 2)
                    {
                        nowR = (nowR + 1) % m;
                    }
                    else if (nowD == 3)
                    {
                        nowC = (nowC - 1 + n) % n;
                    }
                    nowLen++; // 이동한 길이

                    // 이동된 지점에서의 회전 적용
                    if (grid[nowR][nowC] == 'L')
                    {
                        // 좌회전 수행
                        nowD = (nowD - 1 + 4) % 4;
                    }
                    else if (grid[nowR][nowC] == 'R')
                    {
                        // 우회전 수행
                        nowD = (nowD + 1) % 4;
                    }

                    if (nowR == i && nowC == j && nowD == d)
                    {
                        // 이동 후 현재 상태가 출발 지점의 상태(좌표와 빛 발사 방향)와 같은 경우 1개의 사이클을 찾은 것이다.
                        answer.push_back(nowLen);
                        break;
                    }
                }
            }
        }
    }

    sort(answer.begin(), answer.end()); // 오름차순 정렬

    return answer;
}