#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> bomberMan(int n, vector<string> grid)
{
    bool isFull = false, periodFind = false;
    vector<pair<int, int>> bombs;
    int r = grid.size(), c = grid[0].size(), period;
    unordered_map<string, int> counts;

    // 해당 전체는 n 전체에 대해 시뮬레이션 할 경우 시간초과 발생. 그렇지만 특정시점부터 패턴이 주기성을 가지므로 이를 이용하면 된다.
    for (int count = 1; count < n; count++)
    {
        if (isFull)
        {
            isFull = false;
            // 폭탄의 폭발 계산
            while (!bombs.empty())
            {
                int bR = bombs.back().first;
                int bC = bombs.back().second;
                bombs.pop_back();

                grid[bR][bC] = '.';
                if (bR + 1 < r)
                    grid[bR + 1][bC] = '.';
                if (bR - 1 >= 0)
                    grid[bR - 1][bC] = '.';
                if (bC + 1 < c)
                    grid[bR][bC + 1] = '.';
                if (bC - 1 >= 0)
                    grid[bR][bC - 1] = '.';
            }
        }
        else
        {
            isFull = true;
            string before; // 폭탄을 꽉채우기 전 상태를 저장할 문자열
            for (int i = 0; i < r; i++)
            {
                before += grid[i];
                for (int j = 0; j < c; j++)
                {
                    if (grid[i][j] == 'O')
                        bombs.push_back(make_pair(i, j)); // 폭탄의 좌표 추가
                    else
                        grid[i][j] = 'O'; // 폭탄이 아닌 곳은 폭탄으로 채우기
                }
            }

            // 주기를 계산하는 부분
            if (!periodFind)
            {
                if (counts.find(before) == counts.end())
                {
                    counts[before] = count; // 이전에 나오지 않은 패턴은 새로 추가
                }
                else
                {
                    // 이전에 나온적이 있는 패턴이 발견되면 주기를 계산한다.
                    periodFind = true;
                    period = count - counts[before];
                    n -= (count + 1); // 남은 횟수만 계산하기 위해 지금까지의 계산횟수 제거
                    n %= period;      // 주기성을 이용한 시간 절약
                    count = -1;       // for문이 지나고 나면 count가 0부터 시작된다.
                }
            }
        }
    }

    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++)
    {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i];

        if (i != result.size() - 1)
        {
            fout << "\n";
        }
    }

    fout << "\n";

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