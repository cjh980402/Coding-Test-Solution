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
 * Complete the 'insertionSort1' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */
void insertionSort1(int n, vector<int> &arr)
{
    // arr에서 마지막 원소만 정렬되지 않은 값이므로 해당 원소에 대해서만 삽입정렬 수행
    int unsorted = arr[n - 1], bigThanUnsort = n - 1;

    // 첫번째로 등장하는 현재 값보다 큰 값의 위치 찾기 -> 현재 값이 삽입될 위치
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > unsorted)
        {
            bigThanUnsort = i;
            break;
        }
    }

    for (int i = n - 2; i >= bigThanUnsort; i--)
    {
        arr[i + 1] = arr[i]; // 넣을 위치 뒤에 있는 값들을 1칸씩 이동
        printArray(arr);
    }
    arr[bigThanUnsort] = unsorted; // 현재 값을 올바른 위치에 삽입

    printArray(arr);
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

    insertionSort1(n, arr);

    return 0;
}