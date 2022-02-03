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
    vector<vector<int>> maxPluses;
    int maxK = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'G')
            {
                int nowK = 0;

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
                        nowK++;
                }

                if (nowK >= maxK)
                {
                    maxK = nowK;
                    maxPluses.push_back({i, j, nowK});
                }
            }
        }
    }

    int answer = 0;
    vector<int> maxP, second;

    for (int i = maxPluses.size() - 1; i >= 1; i--)
    {
        maxP = maxPluses[i];
        for (int k = -maxP[2]; k <= maxP[2]; k++)
        {
            grid[maxP[0] + k][maxP[1]] = 'U';
            grid[maxP[0]][maxP[1] + k] = 'U';
        }

        for (int j = i - 1; j >= 0; j--)
        {
            bool isPossible = true;
            second = maxPluses[j];

            for (int k = -second[2]; isPossible && k <= second[2]; k++)
            {
                if (grid[second[0] + k][second[1]] == 'U' || grid[second[0]][second[1] + k] == 'U')
                {
                    isPossible = false;
                }
            }

            if (isPossible)
                break;
        }

        if (answer < (1 + 4 * maxP[2]) * (1 + 4 * second[2]))
            answer = (1 + 4 * maxP[2]) * (1 + 4 * second[2]);

        for (int k = -maxP[2]; k <= maxP[2]; k++)
        {
            grid[maxP[0] + k][maxP[1]] = 'G';
            grid[maxP[0]][maxP[1] + k] = 'G';
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