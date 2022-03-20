#include <bits/stdc++.h>

using namespace std;

void printArray(const vector<int> &arr)
{
    for (int i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}

/*
 * Complete the 'insertionSort2' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */
void insertionSort2(int n, vector<int> &arr)
{
    for (int i = 1; i < n; i++)
    {
        int now = arr[i], firstBigthanNow = i;

        // 첫번째로 등장하는 현재 값보다 큰 값의 위치 찾기 -> 현재 값이 삽입될 위치
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > now)
            {
                firstBigthanNow = j;
                break;
            }
        }

        for (int j = i - 1; j >= firstBigthanNow; j--)
        {
            arr[j + 1] = arr[j]; // 넣을 위치 뒤에 있는 값들을 1칸씩 이동
        }
        arr[firstBigthanNow] = now; // 현재 값을 올바른 위치에 삽입

        printArray(arr);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort2(n, arr);
    return 0;
}