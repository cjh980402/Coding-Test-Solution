#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'cavityMap' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY grid as parameter.
 */
vector<string> cavityMap(vector<string> grid)
{
    int n = grid.size();
    // 테두리는 계산하지 않기 위해 1~n-1을 범위로 사용
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            int count = 0;
            if (grid[i][j] > grid[i - 1][j])
                count++;
            if (grid[i][j] > grid[i + 1][j])
                count++;
            if (grid[i][j] > grid[i][j - 1])
                count++;
            if (grid[i][j] > grid[i][j + 1])
                count++;
            // 인접한 지역 4곳보다 깊은 지역이면 X로 표시한다.
            if (count == 4)
                grid[i][j] = 'X';
        }
    }
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.get(); // 정수 입력 후 남아있는 개행 제거

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        getline(cin, grid[i]);
    }

    vector<string> result = cavityMap(grid);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i] << "\n";
    }

    fout.close();

    return 0;
}