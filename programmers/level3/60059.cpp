#include <vector>

using namespace std;

void rotateClock90(vector<vector<int>> &v)
{
    vector<vector<int>> origin(v);
    int n = v.size();

    // 시계방향으로 90도 회전
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            v[j][n - 1 - i] = origin[i][j];
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    int keyL = key.size(), lockL = lock.size();
    // 회전, 이동 등을 수행하였을 때, 열쇠의 1과 자물쇠의 0, 열쇠의 0과 자물쇠의 1이 만나야 열리는 경우이다.
    // 0도, 90도 180도, 270도 회전이므로 4번
    for (int r = 0; r < 4; r++)
    {
        // key에 대해 이동(좌상향, 우상향, 좌하향, 우하향 모두 고려)을 수행하며 lock에 적용할수 있는지 확인하기
        for (int a = 0; a < lockL; a++)
        {
            for (int b = 0; b < lockL; b++)
            {
                int possible[4] = {1, 1, 1, 1}; // 검사를 거쳐도 1이면 적용가능한 경우
                int signA[4] = {1, 1, -1, -1};
                int signB[4] = {1, -1, -1, 1};
                for (int i = 0; i < lockL; i++)
                {
                    for (int j = 0; j < lockL; j++)
                    {
                        // 4개의 방향에 대해 모두 검사
                        for (int k = 0; k < 4; k++)
                        {
                            int keyV = (0 <= i + signA[k] * a && i + signA[k] * a < keyL && 0 <= j + signB[k] * b && j + signB[k] * b < keyL) ? key[i + signA[k] * a][j + signB[k] * b] : 0; // 열쇠 영역을 벗어난 부분은 열쇠의 빈 공간으로 취급하기
                            possible[k] = possible[k] & (lock[i][j] ^ keyV);                                                                                                                 // xor 연산을 이용하면 돌기와 홈이 만나는 경우는 1이 된다.
                        }
                    }
                }
                if (possible[0] || possible[1] || possible[2] || possible[3])
                {
                    return true;
                }
            }
        }

        rotateClock90(key); // 다음 작업을 위해 90도 회전 적용
    }

    return false;
}