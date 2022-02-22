#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'beautifulTriplets' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER d
 *  2. INTEGER_ARRAY arr
 */
int beautifulTriplets(int d, vector<int> arr)
{
    int answer = 0;

    for (int i = 0; i < arr.size() - 2; i++)
    {
        for (int j = i + 1; j < arr.size() - 1; j++)
        {
            if (arr[j] - arr[i] > d)
                break;
            if (arr[j] - arr[i] == d)
            {
                for (int k = j + 1; k < arr.size(); k++)
                {
                    if (arr[k] - arr[j] > d)
                        break;
                    if (arr[k] - arr[j] == d)
                        answer++;
                }
            }
        }
    }

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, d;
    cin >> n >> d;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = beautifulTriplets(d, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}