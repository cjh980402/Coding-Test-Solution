#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r)
{
    int m = matrix.size(), n = matrix[0].size(), minLen = min(m, n);

    // 각 껍질의 가로와 세로 길이는 1보다 커야함
    for (int depth = 0; minLen - 2 * depth > 1; depth++)
    {
        int nowR = r % (2 * (m - 2 * depth) + 2 * (n - 2 * depth) - 4); // depth번째 껍질의 주기성을 이용한 시간 절약
        for (int ri = 0; ri < nowR; ri++)
        {
            int first = matrix[depth][depth];

            // 상단 이동
            for (int i = depth + 1; i < n - depth; i++)
                matrix[depth][i - 1] = matrix[depth][i];

            // 우측 이동
            for (int i = depth + 1; i < m - depth; i++)
                matrix[i - 1][n - 1 - depth] = matrix[i][n - 1 - depth];

            // 하단 이동
            for (int i = n - 2 - depth; i >= depth; i--)
                matrix[m - 1 - depth][i + 1] = matrix[m - 1 - depth][i];

            // 좌측 이동
            for (int i = m - 2 - depth; i >= depth; i--)
                matrix[i + 1][depth] = matrix[i][depth];

            matrix[depth + 1][depth] = first; // 중복된 값이 들어간 곳에 올바른 값 대입
        }
    }

    // 배열 출력
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++)
    {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++)
        {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }
    matrixRotation(matrix, r);

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