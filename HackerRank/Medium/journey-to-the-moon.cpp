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
long long journeyToMoon(int n, const vector<vector<int>> &astronaut)
{
    vector<int> countries(n), count(n, 1);

    // 처음엔 각각 다른 나라로 초기화
    for (int i = 0; i < n; i++)
    {
        countries[i] = i;
    }

    // 각 인원의 나라를 구하는 것은 합집합을 찾는 것과 동일하다. -> union find
    for (const vector<int> &v : astronaut)
    {
        // v[0]과 v[1]은 같은 나라이므로 두 사람이 속한 집합을 합친다.
        int first = countries[v[0]], second = countries[v[1]], country = min(first, second);

        for (int &c : countries)
        {
            if (c == first || c == second)
            {
                count[c]--;
                count[country]++;
                c = country; // 합할 집합으로 변경
            }
        }
    }

    // 시간초과가 나지 않기 위해서는 각 나라의 인원이 담긴 count를 통해 경우의 수를 빠르게 구해야 한다.
    long long sum = 0, answer = 0;
    for (int size : count)
    {
        answer += sum * size;
        sum += size;
    }
    /*위 코드의 원리
    count = {2, 3, 4, 5}일 때, 경우의 수는
    (2*3+2*4+2*5) + (3*4+3*5) + 4*5 -> O(n^2)
    = 0 + 2*3 + (2+3)*4 + (2+3+4)*5 -> O(n)
    = 71
    두 번째 식에서 괄호안에 있는 값이 sum에 해당하게 된다.*/
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

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}