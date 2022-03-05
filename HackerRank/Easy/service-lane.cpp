#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'serviceLane' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY width
 *  2. 2D_INTEGER_ARRAY cases
 */
vector<int> serviceLane(const vector<int> &width, const vector<vector<int>> &cases)
{
    vector<int> answer;

    for (const vector<int> &v : cases)
    {
        int min = 3;
        for (int i = v[0]; i <= v[1]; i++)
        {
            if (min > width[i])
                min = width[i];
        }
        answer.push_back(min);
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, t;
    cin >> n >> t;

    vector<int> width(n);

    for (int i = 0; i < n; i++)
    {
        cin >> width[i];
    }

    vector<vector<int>> cases(t, vector<int>(2));

    for (int i = 0; i < t; i++)
    {
        cin >> cases[i][0] >> cases[i][1];
    }

    vector<int> result = serviceLane(width, cases);

    for (size_t i = 0; i < result.size(); i++)
    {
        fout << result[i] << "\n";
    }

    fout.close();

    return 0;
}