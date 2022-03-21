#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'runningTime' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
int runningTime(vector<int> &arr)
{
    int count = 0;

    // 삽입정렬의 과정
    for (int i = 1; i < arr.size(); i++)
    {
        int now = arr[i], insertPos = i;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] > now)
            {
                insertPos = j;
                break;
            }
        }

        for (int j = i - 1; j >= insertPos; j--)
        {
            arr[j + 1] = arr[j];
            count++; // 이동연산 횟수 세기
        }

        arr[insertPos] = now;
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = runningTime(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}