#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'twoPluses' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY grid as parameter.
 */

int twoPluses(vector<string> grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> pluses;

    // 플러스로 사용 가능한 모든 곳의 정보를 저장한다.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'G')
            {
                // 겹치는 경우가 발생할 때, 플러스의 일부분만 사용해야 문제에서 요구하는 최대의 넓이를 얻을 수 있는 경우가 있기 때문에 0부터 최대길이까지 모두 저장한다.
                pluses.push_back({i, j, 0});

                for (int k = 1; i - k >= 0 && j - k >= 0 && i + k < n && j + k < m; k++)
                {
                    int count = 0;
                    if (grid[i - k][j] == 'G')
                        count++;
                    if (grid[i][j - k] == 'G')
                        count++;
                    if (grid[i + k][j] == 'G')
                        count++;
                    if (grid[i][j + k] == 'G')
                        count++;

                    if (count < 4)
                        break;
                    else
                        pluses.push_back({i, j, k});
                }
            }
        }
    }

    int answer = 0;
    vector<int> first, second;

    // first와 second에 해당하는 모든 경우의 조합을 확인한다.
    for (int i = 0; i < pluses.size() - 1; i++)
    {
        first = pluses[i];
        // first와 second가 겹치는지 확인하기 위해 first의 영역을 U로 표시한다.
        for (int k = -first[2]; k <= first[2]; k++)
        {
            grid[first[0] + k][first[1]] = 'U';
            grid[first[0]][first[1] + k] = 'U';
        }

        for (int j = i + 1; j < pluses.size(); j++)
        {
            second = pluses[j];
            bool isPossible = true;
            for (int k = -second[2]; isPossible && k <= second[2]; k++)
            {
                // first와 second가 겹치는 경우는 유효하지 않은 경우이다.
                if (grid[second[0] + k][second[1]] == 'U' || grid[second[0]][second[1] + k] == 'U')
                {
                    isPossible = false;
                }
            }

            // 현재 상태에서 first와 second가 겹치지 않으면 값을 확인한 후 갱신한다.
            if (isPossible && answer < (1 + 4 * first[2]) * (1 + 4 * second[2]))
            {
                answer = (1 + 4 * first[2]) * (1 + 4 * second[2]);
            }
        }

        // 현재 상태에 대한 검사가 끝났으므로 first의 영역을 원래 값으로 되돌린다.
        for (int k = -first[2]; k <= first[2]; k++)
        {
            grid[first[0] + k][first[1]] = 'G';
            grid[first[0]][first[1] + k] = 'G';
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}