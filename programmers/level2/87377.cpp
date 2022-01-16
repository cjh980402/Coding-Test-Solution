#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<string> solution(vector<vector<int>> line)
{
    vector<pair<int, int>> points;
    int minX = 2147483647, minY = 2147483647, maxX = -2147483648, maxY = -2147483648;

    for (int i = 0; i < line.size() - 1; i++)
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            // 곱해지는 부분이 있어서 값이 매우 커질수 있기 때문에 a~f는 long long을 사용한다
            long long a = line[i][0], b = line[i][1], e = line[i][2],
                      c = line[j][0], d = line[j][1], f = line[j][2];

            long long div = a * d - b * c;
            // 교점이 없거나 교점의 좌표가 정수가 아닌 경우는 제외하기
            if (div == 0 || (b * f - e * d) % div || (e * c - a * f) % div)
                continue;
            int x = (b * f - e * d) / div, y = (e * c - a * f) / div;

            if (x > maxX)
                maxX = x;
            if (x < minX)
                minX = x;
            if (y > maxY)
                maxY = y;
            if (y < minY)
                minY = y;

            points.push_back(pair(x, y));
        }
    }
    // 필요한 공간만 그리는 좌표 문자열 벡터 생성
    vector<string> answer(maxY - minY + 1, string(maxX - minX + 1, '.'));

    for (const pair<int, int> &p : points)
    {
        // 교점에 해당하는 좌표에 * 그리기
        int r = -p.second + maxY;
        int c = p.first - minX;
        answer[r][c] = '*';
    }

    return answer;
}