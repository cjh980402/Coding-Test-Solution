#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'introTutorial' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER V
 *  2. INTEGER_ARRAY arr
 */
int introTutorial(int V, vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == V)
            return i;
    }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int V, n;
    cin >> V >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = introTutorial(V, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}