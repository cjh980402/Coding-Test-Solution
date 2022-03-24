#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
int journeyToMoon(int n, const vector<vector<int>> &astronaut)
{
    int answer = 0;
    vector<int> countries(n), count(n, 1);

    for (int i = 0; i < n; i++)
    {
        countries[i] = i;
    }

    // find country == make union set
    for (const vector<int> &v : astronaut)
    {
        int first = countries[v[0]], second = countries[v[1]], country = min(first, second);

        for (int &c : countries)
        {
            if (c == first || c == second)
            {
                count[c]--;
                count[country]++;
                c = country;
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (count[i] == 0)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (count[j] == 0)
                continue;
            answer += count[i] * count[j];
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, p;
    cin >> n >> p;

    vector<vector<int>> astronaut(p, vector<int>(2));

    for (int i = 0; i < p; i++)
    {
        cin >> astronaut[i][0] >> astronaut[i][1];
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}